//
// Created by lbcos on 06/02/2025.
//

#include "Plane.h"

Plane::Plane(vec3 point, vec3 normal, ObjectMaterial material) {
    this->type = PLANE;
    this->point = point;
    this->normal = normal;
    this->material = material;
};

double Plane::RayIntersection(VectorRay ray) {
    vec3 planeToOrigin = ray.Origin() - this->point;
    float numerator = planeToOrigin.dot(this->normal);
    float denominator = ray.Direction().dot(this->normal);

    if (denominator == 0.0) {
        return -1.0;
    }

    return -numerator / denominator;
};

vec3 Plane::Normal(VectorRay ray) {
    return this->normal;
};
