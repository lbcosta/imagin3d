//
// Created by lbcos on 17/01/2025.
//

#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>
#include "../Object/Object.h"

using namespace std;

struct SceneParams {
  vec3 CameraPosition = vec3(0, 0, 0);
  vec3 LightPosition = vec3(0, 0, 0);
  vec3 LightIntensity = vec3(0, 0, 0);
  vec3 AmbientLight = vec3(0, 0, 0);
  double WindowWidth = 80;
  double WindowHeight = 45;
  int CanvasRowsNumber = 450;
  int CanvasColsNumber = 800;
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
  vec3 CalculateObjectLighting(Object* object, VectorRay ray) const;
};


#endif //SCENE_H