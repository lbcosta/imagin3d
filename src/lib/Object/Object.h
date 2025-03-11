//
// Created by lbcos on 17/01/2025.
//

#ifndef OBJECT_H
#define OBJECT_H

#include "./ObjectType.h"
#include "./ObjectMaterial.h"
#include "../VectorRay/VectorRay.h"
#include "../Transformable/Transformable.h"

class mat3;

class Object : public Transformable {
protected:
  inline static int cursor = 0;
  ObjectMaterial material;
public:
  Object() : id(cursor++) {}
  ~Object() = default;

  int id;
  ObjectType type{};
  virtual double RayIntersection(VectorRay ray) = 0;
  virtual vec3 Normal(VectorRay ray) = 0;
  virtual ObjectMaterial GetMaterialAt(vec3 p) { return this->material; }
};



#endif //OBJECT_H
