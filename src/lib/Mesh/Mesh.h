//
// Created by lbcos on 10/02/2025.
//

#ifndef MESH_H
#define MESH_H

#include "../Object/Object.h"
#include "../Triangle/Triangle.h"

class Mesh final: public Object {
public:
    Mesh(Triangle* triangles[], ObjectMaterial material);

    double RayIntersection(VectorRay ray) override;
    vec3 Normal(VectorRay ray) override;
private:
  Triangle* triangles[];
};



#endif //MESH_H
