//
// Created by lbcos on 17/01/2025.
//

#include "Scene.h"

constexpr double FIXED_Z = -30;
vec3 FIXED_ORIGIN = 0.0;

Scene::Scene(SceneParams sceneParams) {
    this->cameraPosition = sceneParams.CameraPosition;
    this->windowWidth = sceneParams.WindowWidth;
    this->windowHeight = sceneParams.WindowHeight;
    this->canvasRowsNumber = sceneParams.CanvasRowsNumber;
    this->canvasColsNumber = sceneParams.CanvasColsNumber;
    this->objects = sceneParams.Objects;
};

void Scene::Render(const std::function<void()>& renderFunction) {
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
            ObjectMaterial sphereMaterial {vec3(), vec3(), vec3(), 0.0};

            if (Sphere sphere({0.0, 0.0, -100.0}, 40.0, sphereMaterial); sphere.RayIntersection(ray) < 0) {
                pixel = SKYBLUE;
            } else {
                pixel = RED;
            }

            DrawPixel(col, row, pixel);
        }
    }
};
