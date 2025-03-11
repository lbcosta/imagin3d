//
// Created by lbcos on 06/02/2025.
//

#ifndef PLANE_H
#define PLANE_H

#include "PlaneTexture.h"
#include "../Object/Object.h"

class Plane final : public Object {
public:
    Plane(vec3 point, vec3 normal, ObjectMaterial material);
    Plane(vec3 point, vec3 normal, PlaneTexture* texture);

    double RayIntersection(VectorRay ray) override;
    vec3 Normal(VectorRay ray) override;
    void Transform() override;
    ObjectMaterial GetMaterialAt(vec3 p) override;

private:
    PlaneTexture* texture = nullptr;
    vec3 point;
    vec3 normal;
};



#endif //PLANE_H
