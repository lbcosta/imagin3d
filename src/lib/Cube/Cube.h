//
// Created by lbcos on 10/02/2025.
//

#ifndef CUBE_H
#define CUBE_H


#include "../Object/Object.h"

class Cube final: public Object {
public:
    Cube(vec3 center, double size, ObjectMaterial material);

    double RayIntersection(VectorRay ray) override;
    vec3 Normal(VectorRay ray) override;
private:
  vec3 center;
  double size;
};



#endif //CUBE_H
