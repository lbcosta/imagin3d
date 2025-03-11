//
// Created by lbcos on 17/01/2025.
//

#include "Scene.h"

#include <cmath>

#include "raylib.h"

constexpr double FIXED_Z = -30;

Scene::Scene(const SceneParams& sceneParams) {
    this->cameraPosition = sceneParams.CameraPosition;
    this->lightPosition = sceneParams.LightPosition;
    this->lightIntensity = sceneParams.LightIntensity;
    this->ambientLight = sceneParams.AmbientLight;
    this->windowWidth = sceneParams.WindowWidth;
    this->windowHeight = sceneParams.WindowHeight;
    this->canvasRowsNumber = sceneParams.CanvasRowsNumber;
    this->canvasColsNumber = sceneParams.CanvasColsNumber;
    this->objects = sceneParams.Objects;
};

void Scene::Render() {
    Color pixel;

    double deltaY = this->windowHeight / this->canvasRowsNumber;
    double deltaX = this->windowWidth / this->canvasColsNumber;

    for (int row = 0; row <= this->canvasRowsNumber; row++) {
        for (int col = 0; col <= this->canvasColsNumber; col++) {
            vec3 currentPosition = {
                (-this->windowWidth/2) + (deltaX/2) + (col * deltaX),
                (this->windowHeight/2) - (deltaY/2) - (row * deltaY),
                FIXED_Z
            };

            VectorRay ray(this->cameraPosition, currentPosition);
            if (Object* closestObject = this->GetClosestObject(ray); closestObject != nullptr) {
                vec3 color = this->CalculateObjectLighting(closestObject, ray);
                pixel.r = static_cast<unsigned char>(color.r * 255);
                pixel.g = static_cast<unsigned char>(color.g * 255);
                pixel.b = static_cast<unsigned char>(color.b * 255);
                pixel.a = 255;
            } else {
                pixel = GRAY;
            }

            DrawPixel(col, row, pixel);
        }
    }
};

Object* Scene::GetClosestObject(VectorRay ray) {
    Object* closestObject = nullptr;
    double closestIntersection = -1;
    for (Object* object : this->objects) {
        if (double intersectionMoment = object->RayIntersection(ray);
            intersectionMoment > 0.0 && (closestIntersection < 0 || intersectionMoment < closestIntersection)) {
            closestObject = object;
            closestIntersection = intersectionMoment;
        }
    }

    return closestObject;
}

bool Scene::isLightObstructed(int closestObjectId, vec3 intersectionPoint) {
    VectorRay lightRay(this->lightPosition, intersectionPoint);
    Object* closestObjectToLightRay = this->GetClosestObject(lightRay);
    double lightRayIntersectionMoment = closestObjectToLightRay->RayIntersection(lightRay);

    bool isIntersectionMomentValid = lightRayIntersectionMoment > 0.0;
    bool isClosestObjectToLightRayDifferent = closestObjectToLightRay->id != closestObjectId;
    bool isLightRayTooLong = lightRayIntersectionMoment < (lightPosition - intersectionPoint).magnitude();

    return isIntersectionMomentValid && isClosestObjectToLightRayDifferent && isLightRayTooLong;
}

vec3 Scene::CalculateObjectLighting(Object *object, VectorRay ray) {
    double rayIntersectionMoment = object->RayIntersection(ray);
    vec3 intersectionPoint = ray.Origin() + ray.Direction() * rayIntersectionMoment;

    auto [
        ambientReflection,
        diffuseReflection,
        specularReflection,
        shininess
    ] = object->GetMaterialAt(intersectionPoint);

    vec3 ambient = ambientReflection * this->ambientLight;
    vec3 diffuse, specular;

    if (!this->isLightObstructed(object->id, intersectionPoint)) {
        // light vectors
        vec3 v = vec3() - ray.Direction();
        vec3 n = object->Normal(ray);
        vec3 l = (this->lightPosition - intersectionPoint).normalize();
        vec3 r = (n - l) * (n.dot(l) * 2.0);

        // attenuation factors
        double fd = max(n.dot(l), 0.0);
        double fs = pow(max(v.dot(r), 0.0), shininess);

        diffuse = diffuseReflection * this->lightIntensity * fd;
        specular = specularReflection * this->lightIntensity * fs;
    }


    return ambient + diffuse + specular;
}

