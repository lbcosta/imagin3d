//
// Created by lbcos on 09/03/2025.
//

#include "Transformer.h"

void Transformer::Append(mat4 m) {
  this->transformationMatrix = this->transformationMatrix * m;
}

mat4 Transformer::GetMatrix() const {
  return this->transformationMatrix;
}

void Transformer::SetMatrix(mat4 m) {
  this->transformationMatrix = m;
}
