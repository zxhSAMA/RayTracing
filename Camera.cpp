//
// Created by 张向辉 on 2020/12/28.
//

#include "Camera.h"

Camera::Camera() {
    position = Vec3(0,0,0);
    direction = Vec3(0,0,1);
    right = Vec3(0,0,0);
    down = Vec3(0,0,0);
}

Camera::~Camera() = default;

const Vec3 &Camera::getPosition() const {
    return position;
}

const Vec3 &Camera::getDirection() const {
    return direction;
}

const Vec3 &Camera::getRight() const {
    return right;
}

const Vec3 &Camera::getDown() const {
    return down;
}

Camera::Camera(const Vec3& pos, const Vec3& dir, const Vec3& rig, const Vec3& dow) {
    position = pos;
    direction = dir;
    right = rig;
    down = dow;
}
