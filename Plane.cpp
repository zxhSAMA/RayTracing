//
// Created by 张向辉 on 2020/12/29.
//

#include "Plane.h"

Plane::Plane() {
    normal = Vec3(1.0,0,0);
    distance = 1.0;
    color = Color(0.5,0.5,0.5,0.0);
}

Plane::Plane(const Vec3 &n, double d, const Color &c) : normal(n), distance(d), color(c) {}

const Vec3 &Plane::getNormal() const {
    return normal;
}

double Plane::getDistance() const {
    return distance;
}

const Color &Plane::getColor1() const {
    return color;
}

Vec3 Plane::get_normal_at(const Vec3&) const{
    return normal;
}

double Plane::find_intersection(const Ray& ray) {
    double a = ray.getDri().dot_product(normal);
    if (a == 0){ //ray is parallel to plane
        return -1; //not intersect
    }else{
        double b = normal.dot_product(ray.getOri().vec_minus(normal.vec_mult(a)));
        return -1.0*b/a; // distance between ray origin and point intersection
    }
}
