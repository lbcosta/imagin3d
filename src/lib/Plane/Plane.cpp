//
// Created by lbcos on 06/02/2025.
//

#include "Plane.h"

#include <cmath>

Plane::Plane(vec3 point, vec3 normal, ObjectMaterial material) {
    this->type = PLANE;
    this->point = point;
    this->normal = normal;
    this->material = material;
};

Plane::Plane(vec3 point, vec3 normal, PlaneTexture* texture) {
    this->type = PLANE;
    this->point = point;
    this->normal = normal;
    this->texture = texture;
};

double Plane::RayIntersection(VectorRay ray) {
    vec3 planeToOrigin = ray.Origin() - this->point;
    double numerator = planeToOrigin.dot(this->normal);
    double denominator = ray.Direction().dot(this->normal);

    if (denominator == 0.0) {
        return -1.0;
    }

    return -numerator / denominator;
};

vec3 Plane::Normal(VectorRay ray) {
    return this->normal;
};

ObjectMaterial Plane::GetMaterialAt(vec3 p) {
    if (this->texture == nullptr) {
        return this->material;
    }

    vec3 aux;
    if (fabs(this->normal.y) < 0.99) {
        aux = {0.0, 1.0, 0.0};
    } else {
        aux = {1.0, 0.0, 0.0};
    }

    vec3 u = aux.cross(this->normal).normalize();
    vec3 v = this->normal.cross(u);

    vec3 w = p - this->point;
    double x = w.dot(u);
    double y = w.dot(v);

    return this->texture->GetMaterialAt(x, y);
}

void Plane::Transform() {}
