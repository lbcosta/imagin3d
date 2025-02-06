//
// Created by lbcos on 17/01/2025.
//

#include "Scene.h"
#include "raylib.h"

constexpr double FIXED_Z = -30;
vec3 FIXED_ORIGIN = 0.0;

Scene::Scene(const SceneParams& sceneParams) {
    this->cameraPosition = sceneParams.CameraPosition;
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
            vec3 p = {
                (-this->windowWidth/2) + (deltaX/2) + (col * deltaX),
                (this->windowHeight/2) - (deltaY/2) - (row * deltaY),
                FIXED_Z
            };

            VectorRay ray(FIXED_ORIGIN, p);
            Object* closestObject = this->GetClosestObject(ray);

            if (closestObject != nullptr) {
                pixel = RED;
            } else {
                pixel = SKYBLUE;
            }

            DrawPixel(col, row, pixel);
        }
    }
};

Object* Scene::GetClosestObject(VectorRay ray) {
    Object* closestObject = nullptr;
    double closestIntersection = -1;
    for (Object* object : this->objects) {
        double intersectionMoment = object->RayIntersection(ray);
        if (intersectionMoment > 0.0 && (closestIntersection < 0 || intersectionMoment < closestIntersection)) {
            closestObject = object;
            closestIntersection = intersectionMoment;
        }
    }

    return closestObject;
}

