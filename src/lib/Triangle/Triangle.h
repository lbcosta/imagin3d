//
// Created by lbcos on 10/02/2025.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "../Object/Object.h"

class Triangle final: public Object {
public:
    Triangle(vec3 vertex1, vec3 vertex2, vec3 vertex3, ObjectMaterial material);

    double RayIntersection(VectorRay ray) override;
    vec3 Normal(VectorRay ray) override;
private:
  vec3 vertices[3];
};



#endif //TRIANGLE_H
