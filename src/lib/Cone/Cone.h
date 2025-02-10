//
// Created by lbcos on 07/02/2025.
//

#ifndef CONE_H
#define CONE_H


#include "../Object/Object.h"
#include "../Math/mat3.h"

class Cone final: public Object {
public:
    Cone(vec3 baseCenter, double baseRadius, double height, vec3 direction, ObjectMaterial material);

    double RayIntersection(VectorRay ray) override;
    vec3 Normal(VectorRay ray) override;
private:
    vec3 baseCenter;
    double baseRadius;
    double height;
    vec3 direction;

    bool ValidateIntersectionPoint(vec3 intersectionPoint) const;
};



#endif //CONE_H
