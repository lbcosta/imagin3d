//
// Created by lbcos on 17/01/2025.
//

#include "../Math/vec3.h"

#ifndef OBJECTMATERIAL_H
#define OBJECTMATERIAL_H

struct ObjectMaterial {
  vec3 AmbientReflection;
  vec3 DiffuseReflection;
  vec3 SpecularReflection;
  double Shininess;
};

#endif //OBJECTMATERIAL_H
