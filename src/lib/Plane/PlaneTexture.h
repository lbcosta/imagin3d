//
// Created by lbcos on 11/03/2025.
//

#ifndef PLANETEXTURE_H
#define PLANETEXTURE_H

#include "raylib.h"
#include "../Object/ObjectMaterial.h"

enum TextureName {
  WOOD,
  WATER,
  SKY,
  BRICK,
  WHITE_BRICK,
};

class PlaneTexture {
public:
  explicit PlaneTexture(TextureName type, double shininess);
  ObjectMaterial GetMaterialAt(double x, double y) const;

private:
  Color* pixels;
  int nCol;
  int nRow;
  double width;
  double height;
  double shininess;
};



#endif //PLANETEXTURE_H
