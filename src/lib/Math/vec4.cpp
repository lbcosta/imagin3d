//
// Created by lbcos on 19/02/2025.
//

#include "vec4.h"

#include <iostream>
#include <cmath>
#include <stdexcept>

vec4::vec4() : x(0), y(0), z(0), w(0) {}
vec4::vec4(double v) : x(v), y(v), z(v), w(v) {}
vec4::vec4(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
vec4::vec4(vec3 p) : x(p.x), y(p.y), z(p.z), w(1) {}

vec4 vec4::operator+(const vec4& other) const {
    return {x + other.x, y + other.y, z + other.z, w + other.w};
}

vec4 vec4::operator-(const vec4& other) const {
    return {x - other.x, y - other.y, z - other.z, w - other.w};
}

vec4 vec4::operator*(double scalar) const {
    return {x * scalar, y * scalar, z * scalar, w * scalar};
}

vec4 vec4::operator/(double scalar) const {
    if (scalar == 0) throw std::runtime_error("Divisão por zero!");
    return {x / scalar, y / scalar, z / scalar, w / scalar};
}

vec4 vec4::operator*(const vec4& other) const {
    return {x * other.x, y * other.y, z * other.z, w * other.w};
}

double vec4::dot(const vec4& other) const {
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

double vec4::magnitude() const {
    return std::sqrt(x * x + y * y + z * z + w * w);
}

vec4 vec4::normalize() const {
    double mag = magnitude();
    if (mag == 0) throw std::runtime_error("Vetor nulo não pode ser normalizado!");
    return *this / mag;
}

vec4 vec4::xyz() const { return {x, y, z, 0}; }
vec4 vec4::xyzw() const { return {x, y, z, w}; }

vec4 vec4::rgba() const { return {r, g, b, a}; }
vec4 vec4::bgra() const { return {b, g, r, a}; }

void vec4::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ", " << w << ")\n";
}

