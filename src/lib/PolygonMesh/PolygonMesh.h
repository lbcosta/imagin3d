//
// Created by lbcos on 11/02/2025.
//

#ifndef POLYGONMESH_H
#define POLYGONMESH_H

#include <vector>
#include "../Object/Object.h"
#include "../Triangle/Triangle.h"

using namespace std;

class PolygonMesh: public Object {
public:
    PolygonMesh(vector<vec3> vertices, ObjectMaterial material);

    double RayIntersection(VectorRay ray) override;
    vec3 Normal(VectorRay ray) override;
    void Transform() override;
protected:
    PolygonMesh() = default;
    vector<Triangle> triangles;
};



#endif //POLYGONMESH_H
