//
// Created by lbcos on 17/01/2025.
//

#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "../Object/Object.h"
#include "Parameters.h"

using namespace std;

struct SceneParams {
  vec3 CameraPosition = FIXED_ORIGIN;
  vec3 LightPosition = vec3(0, 0, 0);
  vec3 LightIntensity = vec3(0, 0, 0);
  vec3 AmbientLight = vec3(0, 0, 0);
  double WindowWidth = WINDOW_WIDTH;
  double WindowHeight = WINDOW_HEIGHT;
  int CanvasRowsNumber = N_ROW;
  int CanvasColsNumber = N_COL;
  vector<Object*> Objects;
 };


class Scene {
public:
  explicit Scene(const SceneParams& sceneParams);
  void Render();
private:
  vec3 cameraPosition;
  vec3 lightPosition;
  vec3 lightIntensity;
  vec3 ambientLight;
  double windowWidth;
  double windowHeight;
  int canvasRowsNumber;
  int canvasColsNumber;
  vector<Object*> objects;

  Object* GetClosestObject(VectorRay ray);
  vec3 CalculateObjectLighting(Object* object, VectorRay ray);
  bool isLightObstructed(int closestObjectId, vec3 intersectionPoint);
};


#endif //SCENE_H