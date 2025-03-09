//
// Created by lbcos on 06/02/2025.
//

#ifndef PLANE_H
#define PLANE_H

#include "../Object/Object.h"

class Plane final : public Object {
public:
    Plane(vec3 point, vec3 normal, ObjectMaterial material);

    double RayIntersection(VectorRay ray) override;
    vec3 Normal(VectorRay ray) override;
    void Transform() override;

private:
    vec3 point;
    vec3 normal;
};



#endif //PLANE_H
