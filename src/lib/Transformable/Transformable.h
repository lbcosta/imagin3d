//
// Created by lbcos on 09/03/2025.
//

#ifndef TRANSFORMABLE_H
#define TRANSFORMABLE_H

#include "../Transformer/Transformer.h"
#include "../Math/vec3.h"

class Transformable {
public:
  virtual ~Transformable() = default;

  mat4 GetTransformationMatrix() const;
  void SetTransformationMatrix(mat4 matrix);
  Transformable *Translate(vec3 t);
  Transformable *Scale(vec3 s, vec3 reference);

  vec3 TransformPoint(vec3 p) const;
  virtual void Transform() = 0;

private:
  Transformer transformer;
};



#endif //TRANSFORMABLE_H
