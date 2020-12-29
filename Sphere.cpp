//
// Created by 张向辉 on 2020/12/29.
//

#include "Sphere.h"

Sphere::Sphere() {
    center = Vec3(0,0,0);
    radius = 1.0;
    color = Color(0.5,0.5,0.5,0.0);
}

Sphere::Sphere(const Vec3 &cen, double rad, const Color &col) : center(cen), radius(rad), color(col) {}

const Vec3 &Sphere::getCenter() const {
    return center;
}

double Sphere::getRadius() const {
    return radius;
}

const Color &Sphere::getColor() const {
    return color;
}

Sphere::~Sphere() = default;

