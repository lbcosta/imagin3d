//
// Created by lbcos on 11/03/2025.
//

#include "PlaneTexture.h"

#include <cmath>
#include <stdexcept>
#include "../Math/vec3.h"

PlaneTexture::PlaneTexture(TextureName type, double shininess) {
  const char* fileName = nullptr;
  switch (type) {
    case WOOD:
      fileName = "../assets/wood.png";
      break;
  }

  Image img = LoadImage(fileName);
  if (!img.data) throw std::runtime_error("Failed to load texture");

  this->pixels = LoadImageColors(img);
  this->nCol = img.width;
  this->nRow = img.height;
  this->width = img.width;
  this->height = img.height;
  this->shininess = shininess;
}

ObjectMaterial PlaneTexture::GetMaterialAt(double x, double y) const {
  int texelX = (static_cast<int>(roundf(x / this->width * this->nCol)) % this->nCol + this->nCol) % this->nCol;
  int texelY = (static_cast<int>(roundf(y / height * this->nRow)) % this->nRow + this->nRow) % this->nRow;

  Color color = pixels[texelY * this->nCol + texelX];
  vec3 reflection = { color.r / 255.0, color.g / 255.0, color.b / 255.0 };

  return ObjectMaterial{
    .AmbientReflection = reflection,
    .DiffuseReflection = reflection,
    .SpecularReflection = reflection,
    .Shininess = shininess
  };
}
