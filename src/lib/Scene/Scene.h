//
// Created by lbcos on 17/01/2025.
//

#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"
#include <functional>
#include <vector>
#include "../Object/Object.h"
#include "../Sphere/Sphere.h"

struct SceneParams {
  vec3 CameraPosition;
  double WindowWidth{};
  double WindowHeight{};
  int CanvasRowsNumber{};
  int CanvasColsNumber{};
  std::vector<Object>* Objects{};
 };


class Scene {
public:
  explicit Scene(SceneParams sceneParams);
  void Render(const std::function<void()>& renderFunction);
private:
  vec3 cameraPosition;
  double windowWidth;
  double windowHeight;
  int canvasRowsNumber;
  int canvasColsNumber;
  std::vector<Object>* objects;
};


#endif //SCENE_H