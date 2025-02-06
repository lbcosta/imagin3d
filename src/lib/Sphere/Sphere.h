//
// Created by lbcos on 17/01/2025.
//

#ifndef SPHERE_H
#define SPHERE_H

#include "../Object/Object.h"

class Sphere final : public Object {
public:
  Sphere(vec3 center, double radius, ObjectMaterial material);

  double RayIntersection(VectorRay ray) override;
  vec3 Normal(VectorRay ray) override;

private:
  vec3 center;
  double radius;
};



#endif //SPHERE_H
