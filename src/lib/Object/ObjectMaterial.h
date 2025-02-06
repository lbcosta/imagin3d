//
// Created by lbcos on 17/01/2025.
//
#pragma once

#include "../Math/vec3.h"

#ifndef OBJECTMATERIAL_H
#define OBJECTMATERIAL_H

struct ObjectMaterial {
  vec3 AmbientReflection = vec3(0, 0, 0);
  vec3 DiffuseReflection = vec3(0, 0, 0);
  vec3 SpecularReflection = vec3(0, 0, 0);
  double Shininess = 0.0;
};

#endif //OBJECTMATERIAL_H
