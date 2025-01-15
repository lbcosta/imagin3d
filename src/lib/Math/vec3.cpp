//
// Created by lbcos on 14/01/2025.
//

#include "vec3.h"

// Construtores
vec3::vec3() : x(0), y(0), z(0) {}
vec3::vec3(float v) : x(v), y(v), z(v) {}
vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}

// Operadores matemáticos
vec3 vec3::operator+(const vec3& other) const {
    return vec3(x + other.x, y + other.y, z + other.z);
}

vec3 vec3::operator-(const vec3& other) const {
    return vec3(x - other.x, y - other.y, z - other.z);
}

vec3 vec3::operator*(float scalar) const {
    return vec3(x * scalar, y * scalar, z * scalar);
}

vec3 vec3::operator/(float scalar) const {
    if (scalar == 0) throw std::runtime_error("Divisão por zero!");
    return vec3(x / scalar, y / scalar, z / scalar);
}

// Produto escalar
float vec3::dot(const vec3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

// Produto vetorial
vec3 vec3::cross(const vec3& other) const {
    return vec3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

// Norma (magnitude)
float vec3::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Normalização
vec3 vec3::normalize() const {
    float mag = magnitude();
    if (mag == 0) throw std::runtime_error("Vetor nulo não pode ser normalizado!");
    return *this / mag;
}

// Swizzling para subvetores
vec3 vec3::xy() const { return vec3(x, y, 0); }
vec3 vec3::yz() const { return vec3(0, y, z); }
vec3 vec3::zx() const { return vec3(z, 0, x); }

vec3 vec3::rgb() const { return vec3(r, g, 0); }
vec3 vec3::gbr() const { return vec3(g, b, r); }
vec3 vec3::brg() const { return vec3(b, r, g); }

// Print para depuração
void vec3::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")\n";
}

