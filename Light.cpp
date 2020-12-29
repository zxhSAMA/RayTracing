//
// Created by 张向辉 on 2020/12/28.
//

#include "Light.h"

Light::Light() {
    position = Vec3(0, 0, 0);
    color = Color(1.0, 1.0, 1.0, 0.0);
}

Light::Light(const Vec3 &pos, const Color &col) : position(pos), color(col) {}

Light::~Light() = default;

const Vec3 &Light::getPosition() const {
    return position;
}

const Color &Light::getColor() const {
    return color;
}
