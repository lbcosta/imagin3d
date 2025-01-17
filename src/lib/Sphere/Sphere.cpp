//
// Created by lbcos on 17/01/2025.
//

#include "Sphere.h"

#include <cmath>

Sphere::Sphere(vec3 center, double radius, ObjectMaterial material) {
    this->type = SPHERE;
    this->center = center;
    this->radius = radius;
    this->material = material;
};

double Sphere::RayIntersection(VectorRay ray) {
    vec3 v = ray.Origin() - this->center;

    double a = ray.Direction().dot(ray.Direction());
    double b = 2.0 * v.dot(ray.Direction());
    double c = v.dot(v) - std::pow(this->radius, 2.0);

    double discriminant = b * b - 4.0 * a * c;

    if (discriminant <= 0.0) {
        return -1.0;
    }

    double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t2 = (-b + sqrt(discriminant)) / (2.0 * a);

    return t1 < t2 ? t1 : t2;
};

vec3 Sphere::Normal(VectorRay ray) {
    vec3 p = ray.Origin() + ray.Direction() * this->RayIntersection(ray);
    vec3 N = p - this->center;
    vec3 n = N.normalize();

    return n;
};






