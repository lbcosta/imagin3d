//
// Created by lbcos on 10/02/2025.
//

#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include "../PolygonMesh/PolygonMesh.h"
#include "../Triangle/Triangle.h"

using namespace std;

class Cube final: public PolygonMesh {
public:
    Cube(vec3 center, double size, ObjectMaterial material);
};



#endif //CUBE_H
