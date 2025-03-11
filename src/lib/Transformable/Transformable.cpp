//
// Created by lbcos on 09/03/2025.
//

#include "Transformable.h"

#include <cmath>
#include <stdexcept>

#include "raylib.h"

mat4 Transformable::GetTransformationMatrix() const {
    return this->transformer.GetMatrix();
}

void Transformable::SetTransformationMatrix(mat4 matrix) {
    this->transformer.SetMatrix(matrix);
}

Transformable* Transformable::Translate(vec3 t) {
    this->transformer.Append({
        {1, 0, 0, t.x},
        {0, 1, 0, t.y},
        {0, 0, 1, t.z},
        {0, 0, 0, 1}
    });

    return this;
}

Transformable* Transformable::Scale(vec3 s, vec3 reference) {
    if (s.x == 0) s.x = 1;
    if (s.y == 0) s.y = 1;
    if (s.z == 0) s.z = 1;

    this->Translate({reference.x - 0, reference.y - 0, reference.z - 0});
    this->transformer.Append({
        {s.x, 0, 0, 0},
        {0, s.y, 0, 0},
        {0, 0, s.z, 0},
        {0, 0, 0, 1}
    });
    this->Translate({0 - reference.x, 0 - reference.y, 0 - reference.z});

    return this;
}

Transformable* Transformable::RotateX(double angle, vec3 reference) {
    double sen = sin(angle*PI/180.0);
    double coss = cos(angle*PI/180.0);

    this->Translate({reference.x - 0, reference.y - 0, reference.z - 0});
    this->transformer.Append({
        {1, 0, 0, 0},
        {0, coss, -sen, 0},
        {0, sen, coss, 0},
        {0, 0, 0, 1},
    });
    this->Translate({0 - reference.x, 0 - reference.y, 0 - reference.z});

    return this;
}

Transformable* Transformable::RotateY(double angle, vec3 reference) {
    double sen = sin(angle*PI/180.0);
    double coss = cos(angle*PI/180.0);

    this->Translate({reference.x - 0, reference.y - 0, reference.z - 0});
    this->transformer.Append({
        {coss, 0, sen, 0},
        {0, 1, 0, 0},
        {-sen, 0, coss, 0},
        {0, 0, 0, 1},
    });
    this->Translate({0 - reference.x, 0 - reference.y, 0 - reference.z});

    return this;
}

Transformable* Transformable::RotateZ(double angle, vec3 reference) {
    double sen = sin(angle*PI/180.0);
    double coss = cos(angle*PI/180.0);

    this->Translate({reference.x - 0, reference.y - 0, reference.z - 0});
    this->transformer.Append({
        {coss, -sen, 0, 0},
        {sen, coss, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    });
    this->Translate({0 - reference.x, 0 - reference.y, 0 - reference.z});

    return this;
}


Transformable* Transformable::Rotate(double angle, vec3 p1, vec3 p2) {
    vec3 u = (p2 - p1).normalize();
    double sen = sin(angle*PI/180.0);
    double coss = cos(angle*PI/180.0);

    double x = sen * u.x;
    double y = sen * u.y;
    double z = sen * u.z;
    double w = coss;

    this->Translate({p1.x - 0, p1.y - 0, p1.z - 0});
    this->transformer.Append({
        {(w*w + x*x - y*y - z*z), 2 * (x*y - w*z), 2 * (x*z + w*y), 0},
        {2 * (x*y + w*z), (w*w - x*x + y*y - z*z), 2 * (y*z - w*x), 0},
        {2 * (x*z - w*y), 2 * (y*z + w*x), (w*w - x*x - y*y + z*z), 0},
        {0, 0, 0, 1},
    });
    this->Translate({0 - p1.x, 0 - p1.y, 0 - p1.z});

    return this;
}

Transformable* Transformable::Shear(double angle, ShearPlane plane, ShearDirection direction, vec3 reference) {
    double tg = tan(angle*PI/180.0);

    mat4 M = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    };

    if (plane == XY) {
        switch (direction) {
            case X: M[0].y = tg;break;
            case Y: M[1].x = tg;break;
            default: throw std::runtime_error("Cisalhamento em XY precisa ser nas direcoes X ou Y!");
        }
    }

    if (plane == XZ) {
        switch (direction) {
            case X: M[0].z = tg;break;
            case Z: M[2].x = tg;break;
            default: throw std::runtime_error("Cisalhamento em XZ precisa ser nas direcoes X ou Z!");
        }
    }

    if (plane == YZ) {
        switch (direction) {
            case Y: M[1].z = tg;break;
            case Z: M[2].y = tg;break;
            default: throw std::runtime_error("Cisalhamento em YZ precisa ser nas direcoes Y ou Z!");
        }
    }

    this->Translate({reference.x - 0, reference.y - 0, reference.z - 0});
    this->transformer.Append(M);
    this->Translate({0 - reference.x, 0 - reference.y, 0 - reference.z});

    return this;
}

Transformable* Transformable::Reflect(vec3 p1, vec3 p2, vec3 p3) {
    vec3 v1 = p2 - p1;
    vec3 v2 = p3 - p1;
    vec3 n = v1.cross(v2).normalize();

    this->Translate({p1.x - 0, p1.y - 0, p1.z - 0});
    this->transformer.Append({
        {1 - 2 * (n.x * n.x), -2 * (n.x * n.y), -2 * (n.x * n.z), 0},
        {-2 * (n.y * n.x), 1 - 2 * (n.y * n.y), -2 * (n.y * n.z), 0},
        {-2 * (n.z * n.x), -2 * (n.z * n.y), 1 - 2 * (n.z * n.z), 0},
        {0, 0, 0, 1}
    });
    this->Translate({0 - p1.x, 0 - p1.y, 0 - p1.z});
    return this;
}

vec3 Transformable::TransformPoint(vec3 p) const {
    vec4 p_4d(p.x, p.y, p.z, 1);
    vec4 new_p_4d = this->transformer.GetMatrix() * p_4d;
    return new_p_4d.xyz();
}