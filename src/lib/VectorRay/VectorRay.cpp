//
// Created by lbcos on 17/01/2025.
//

#include "VectorRay.h"

VectorRay::VectorRay(vec3 start, vec3 end) {
  this->start = start;
  this->end = end;
}

vec3 VectorRay::Origin() const {
  return this->start;
}

// Return normalized direction
vec3 VectorRay::Direction() const {
  vec3 d = this->end - this->start;
  return d.normalize();
}
