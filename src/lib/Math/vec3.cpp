//
// Created by lbcos on 14/01/2025.
//

#include "vec3.h"

#include <iostream>
#include <cmath>
#include <stdexcept>

vec3::vec3() : x(0), y(0), z(0) {}
vec3::vec3(double v) : x(v), y(v), z(v) {}
vec3::vec3(double x, double y, double z) : x(x), y(y), z(z) {}

vec3 vec3::operator+(const vec3& other) const {
    return {x + other.x, y + other.y, z + other.z};
}

vec3 vec3::operator-(const vec3& other) const {
    return {x - other.x, y - other.y, z - other.z};
}

vec3 vec3::operator*(double scalar) const {
    return {x * scalar, y * scalar, z * scalar};
}

vec3 vec3::operator/(double scalar) const {
    if (scalar == 0) throw std::runtime_error("Divisão por zero!");
    return {x / scalar, y / scalar, z / scalar};
}

double vec3::dot(const vec3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

vec3 vec3::cross(const vec3& other) const {
    return {
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    };
}

double vec3::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

vec3 vec3::normalize() const {
    double mag = magnitude();
    if (mag == 0) throw std::runtime_error("Vetor nulo não pode ser normalizado!");
    return *this / mag;
}

vec3 vec3::xy() const { return {x, y, 0}; }
vec3 vec3::yz() const { return {0, y, z}; }
vec3 vec3::zx() const { return {z, 0, x}; }

vec3 vec3::rgb() const { return {r, g, 0}; }
vec3 vec3::gbr() const { return {g, b, r}; }
vec3 vec3::brg() const { return {b, r, g}; }

void vec3::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")\n";
}

