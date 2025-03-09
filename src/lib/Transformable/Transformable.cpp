//
// Created by lbcos on 09/03/2025.
//

#include "Transformable.h"

Transformable *Transformable::Translate(vec3 t) {
    mat4 m(
        {1, 0, 0, t.x},
        {0, 1, 0, t.y},
        {0, 0, 1, t.z},
        {0, 0, 0, 1}
    );

    this->transformer.Append(m);
    return this;
}

vec3 Transformable::TransformPoint(vec3 p) const {
    vec4 p_4d(p.x, p.y, p.z, 1);
    vec4 new_p_4d = this->transformer.GetMatrix() * p_4d;
    return new_p_4d.xyz();
}