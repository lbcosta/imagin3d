//
// Created by lbcos on 07/02/2025.
//

#ifndef CYLINDER_H
#define CYLINDER_H

#include "../Object/Object.h"
#include "../Math/mat3.h"

class Cylinder final: public Object {
public:
    Cylinder(vec3 baseCenter, double baseRadius, double height, vec3 direction, ObjectMaterial material);

    double RayIntersection(VectorRay ray) override;
    vec3 Normal(VectorRay ray) override;
    void Transform() override;
private:
    vec3 baseCenter;
    double baseRadius;
    double height;
    vec3 direction;

    mat3 GetProjectionMatrix() const;
    bool ValidateIntersectionPoint(vec3 intersectionPoint) const;
};



#endif //CYLINDER_H
