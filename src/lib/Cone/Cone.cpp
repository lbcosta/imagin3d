//
// Created by lbcos on 07/02/2025.
//

#include <cmath>
#include "Cone.h"

Cone::Cone(vec3 baseCenter, double baseRadius, double height, vec3 direction, ObjectMaterial material) {
    this->type = CONE;
    this->baseCenter = baseCenter;
    this->baseRadius = baseRadius;
    this->height = height;
    this->direction = direction;
    this->material = material;
}

double Cone::RayIntersection(VectorRay ray) {
    vec3 coneAxis = this->direction.normalize();
    mat3 Q = mat3::OuterProduct(coneAxis, coneAxis);
    mat3 M = mat3(1.0) - Q;
    vec3 s = ray.Origin() - this->baseCenter;

    // a = (d.M.d.h^2) - (d.Q.d.r^2)
    double a1 = ray.Direction().dot(M * ray.Direction()) * pow(this->height, 2.0);
    double a2 = ray.Direction().dot(Q * ray.Direction()) * pow(this->baseRadius, 2.0);
    double a = a1 - a2;

    // b = (2.d.M.s.h^2) + (2.d.Q.d.H.r^2) - (2.d.Q.s.r^2)
    double b1 = 2.0 * s.dot(M * ray.Direction()) * pow(this->height, 2.0);
    double b2 = 2.0 * ray.Direction().dot(Q * this->direction) * this->height * pow(this->baseRadius, 2.0);
    double b3 = 2.0 * s.dot(Q * ray.Direction()) * pow(this->baseRadius, 2.0);
    double b = b1 + b2 - b3;

    // c = (s.M.s.h^2) + (2.d.Q.s.h.r^2) - (s.Q.s.r^2) - (h^2.r^2)
    double c1 = s.dot(M * s) * pow(this->height, 2.0);
    double c2 = 2.0 * s.dot(Q * this->direction) * this->height * pow(this->baseRadius, 2.0);
    double c3 = s.dot(Q * s) * pow(this->baseRadius, 2.0);
    double c4 = pow(this->height, 2.0) * pow(this->baseRadius, 2.0);
    double c = c1 + c2 - c3 - c4;

    if (a == 0.0) {
        double t1 = -c / b;
        vec3 intersectionPoint1 = ray.Origin() + ray.Direction() * t1;
        if (this->ValidateIntersectionPoint(intersectionPoint1)) {
            return t1;
        }

        return -1.0;
    }

    double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0.0) {
        return -1.0;
    }

    if (discriminant == 0.0) {
        double t = -b / (2.0 * a);
        vec3 intersectionPoint = ray.Origin() + ray.Direction() * t;
        if (this->ValidateIntersectionPoint(intersectionPoint)) {
            return t;
        }

        return -1.0;
    }

    double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t2 = (-b + sqrt(discriminant)) / (2.0 * a);

    vec3 intersectionPoint1 = ray.Origin() + ray.Direction() * t1;
    vec3 intersectionPoint2 = ray.Origin() + ray.Direction() * t2;

    bool isValidIntersectionPoint1 = this->ValidateIntersectionPoint(intersectionPoint1);
    bool isValidIntersectionPoint2 = this->ValidateIntersectionPoint(intersectionPoint2);

    if (isValidIntersectionPoint1 && isValidIntersectionPoint2) {
        return t1 < t2 ? t1 : t2;
    }

    if (isValidIntersectionPoint1) {
        return t1;
    }

    if (isValidIntersectionPoint2) {
        return t2;
    }

    return -1.0;
}

bool Cone::ValidateIntersectionPoint(vec3 intersectionPoint) const {
    vec3 baseToIntersection = intersectionPoint - this->baseCenter;
    double projection = baseToIntersection.dot(this->direction);
    return projection >= 0.0 && projection <= this->height;
}


vec3 Cone::Normal(VectorRay ray) {
    double intersectionMoment = this->RayIntersection(ray);
    vec3 intersectionPoint = ray.Origin() + ray.Direction() * intersectionMoment;
    vec3 baseToIntersection = intersectionPoint - this->baseCenter;
    vec3 projection = this->direction * this->direction.dot(baseToIntersection);
    vec3 normal = (baseToIntersection - projection).normalize();

    return normal;
}