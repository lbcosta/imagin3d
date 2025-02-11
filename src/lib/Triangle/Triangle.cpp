//
// Created by lbcos on 10/02/2025.
//

#include "Triangle.h"

Triangle::Triangle(vec3 vertex1, vec3 vertex2, vec3 vertex3, ObjectMaterial material) {
    this->type = TRIANGLE;
    this->material = material;
    this->vertices[0] = vertex1;
    this->vertices[1] = vertex2;
    this->vertices[2] = vertex3;


    vec3 v1 = this->vertices[1] - this->vertices[0];
    vec3 v2 = this->vertices[2] - this->vertices[0];
    this->N = v1.cross(v2);
}

double Triangle::RayIntersection(VectorRay ray) {
    vec3 v = ray.Origin() - this->vertices[0];
    vec3 normal = this->Normal(ray);

    double a = ray.Direction().dot(normal);
    if (a == 0.0) return -1.0;

    // Ponto de interseção
    double intersectionMoment = -v.dot(normal) / a;
    vec3 intersectionPoint = ray.Origin() + ray.Direction() * intersectionMoment;

    // Coordenadas Baricêntricas
    vec3 r1 = this->vertices[0] - intersectionPoint;
    vec3 r2 = this->vertices[1] - intersectionPoint;
    vec3 r3 = this->vertices[2] - intersectionPoint;

    // Validação: P está no interior do triângulo?
    double alpha1 = r3.cross(r1).dot(normal) / this->N.magnitude();
    if (alpha1 < 0) return -1.0;

    double alpha2 = r1.cross(r2).dot(normal) / this->N.magnitude();
    if (alpha2 < 0) return -1.0;

    double alpha3 = 1 - alpha1 - alpha2;
    if (alpha3 < 0) return -1.0;

    return intersectionMoment;
}

vec3 Triangle::Normal(VectorRay ray) {
    return this->N.normalize();
}
