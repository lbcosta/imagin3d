//
// Created by lbcos on 07/02/2025.
//

#include <cmath>
#include "Cylinder.h"

Cylinder::Cylinder(vec3 baseCenter, double baseRadius, double height, vec3 direction, ObjectMaterial material) {
    this->type = CYLINDER;
    this->baseCenter = baseCenter;
    this->baseRadius = baseRadius;
    this->height = height;
    this->direction = direction;
    this->material = material;
}

double Cylinder::RayIntersection(VectorRay ray) {
        mat3 M = this->GetProjectionMatrix();
        vec3 v = ray.Origin() - this->baseCenter;

        double a = (M * ray.Direction()).dot(ray.Direction());
        double b = 2.0 * (M * ray.Direction()).dot(v);
        double c = (M * v).dot(v) - pow(this->baseRadius, 2.0);

        if (a == 0.0) {
            double t = -c / b;
            vec3 intersectionPoint = ray.Origin() + ray.Direction() * t;

            if (this->ValidateIntersectionPoint(intersectionPoint)) {
                return t;
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

        // calculate t values
        double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
        double t2 = (-b + sqrt(discriminant)) / (2.0 * a);

        // calculate intersection points
        vec3 intersectionPoint1 = ray.Origin() + ray.Direction() * t1;
        vec3 intersectionPoint2 = ray.Origin() + ray.Direction() * t2;

        // validate intersection points
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

vec3 Cylinder::Normal(VectorRay ray) {
    double t = this->RayIntersection(ray);
    vec3 intersectionPoint = ray.Origin() + ray.Direction() * t;
    vec3 baseToIntersection = intersectionPoint - this->baseCenter;
    vec3 projection = this->direction * this->direction.dot(baseToIntersection);
    vec3 normal = (baseToIntersection - projection).normalize();

    return normal;
}

mat3 Cylinder::GetProjectionMatrix() const {
    mat3 identityMatrix(1.0);

    vec3 cylinderAxis = this->direction.normalize();
    mat3 cylinderAxisMatrix = mat3::OuterProduct(cylinderAxis, cylinderAxis);

    mat3 projectionMatrix = identityMatrix - cylinderAxisMatrix;
    return projectionMatrix;
}

bool Cylinder::ValidateIntersectionPoint(vec3 intersectionPoint) const {
    vec3 baseToIntersection = intersectionPoint - this->baseCenter;
    double projection = baseToIntersection.dot(this->direction);
    return projection >= 0.0 && projection <= this->height;
}
