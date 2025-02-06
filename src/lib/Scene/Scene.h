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
  double windowWidth;
  double windowHeight;
  int canvasRowsNumber;
  int canvasColsNumber;
  vector<Object*> objects;

  Object* GetClosestObject(VectorRay ray);
};


#endif //SCENE_H