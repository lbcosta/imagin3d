//
// Created by lbcos on 17/01/2025.
//

#ifndef OBJECT_H
#define OBJECT_H

#include "./ObjectType.h"
#include "./ObjectMaterial.h"
#include "../VectorRay/VectorRay.h"

class Object {
protected:
  inline static int cursor = 0;
public:
  Object() : id(cursor++) {}
  virtual ~Object() = default;

  int id;
  ObjectType type;
  ObjectMaterial material;
  virtual double RayIntersection(VectorRay ray) = 0;
  virtual vec3 Normal(VectorRay ray) = 0;
};



#endif //OBJECT_H
