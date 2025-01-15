//
// Created by lbcos on 14/01/2025.
//

#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>
#include <stdexcept>

class vec3 {
public:
    union {
        struct { float x, y, z; }; // Coordenadas
        struct { float r, g, b; }; // Cores
    };

    // Construtores
    vec3();
    vec3(float v);
    vec3(float x, float y, float z);

    // Operadores matemáticos
    vec3 operator+(const vec3& other) const;
    vec3 operator-(const vec3& other) const;
    vec3 operator*(float scalar) const;
    vec3 operator/(float scalar) const;

    // Produto escalar
    float dot(const vec3& other) const;

    // Produto vetorial
    vec3 cross(const vec3& other) const;

    // Norma (magnitude)
    float magnitude() const;

    // Normalização
    vec3 normalize() const;

    // Swizzling para subvetores
    vec3 xy() const;
    vec3 yz() const;
    vec3 zx() const;

    vec3 rgb() const;
    vec3 gbr() const;
    vec3 brg() const;

    // Print para depuração
    void print() const;
};

#endif // VEC3_H
