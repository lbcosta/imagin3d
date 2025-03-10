//
// Created by lbcos on 09/03/2025.
//

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "../Math/mat4.h"

class Transformer {
public:
  void Append(mat4 m);
  mat4 GetMatrix() const;
  void SetMatrix(mat4 m);
private:
  mat4 transformationMatrix = mat4(1);
};



#endif //TRANSFORMER_H
