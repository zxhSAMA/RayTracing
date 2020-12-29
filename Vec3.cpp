//
// Created by 张向辉 on 2020/12/28.
//

#include "Vec3.h"
#include <cmath>

double Vec3::getX() const {
    return x;
}

double Vec3::getY() const {
    return y;
}

double Vec3::getZ() const {
    return z;
}

Vec3::Vec3():x(0),y(0),z(0){}

Vec3::Vec3(double i, double j, double k):x(i),y(j),z(k){}

double Vec3::magnitude() const {
    return sqrt(x*x+y*y+z*z);
}

Vec3 Vec3::normalize() const {
    double mag = this->magnitude();
    return Vec3(x/mag,y/mag,z/mag);
}

Vec3 Vec3::negative() const {
    return Vec3(-x,-y,-z);
}

double Vec3::dot_product(const Vec3 &v) const {
    return x*v.getX()+y*v.getY()+z*v.getZ();
}

Vec3 Vec3::cross_product(const Vec3 &v) const {
    double cross_x = y*v.getZ()-z*v.getY();
    double cross_y = z*v.getX()-x*v.getZ();
    double cross_z = x*v.getY()-y*v.getX();
    return Vec3(cross_x,cross_y,cross_z);
}

Vec3 Vec3::vec_add(const Vec3 &v) const {
    return Vec3(x+v.getX(),y+v.getY(),z+v.getZ());
}

Vec3 Vec3::vec_mult(double scalar) const {
    return Vec3(x*scalar,y*scalar,z*scalar);
}

std::ostream &operator<<(std::ostream &ost, Vec3 &v) {
    ost<<"x = "<<v.getX()<<", y = "<<v.getY()<<", z = "<<v.getZ();
    return ost;
}

Vec3 Vec3::vec_minus(const Vec3 &v) const {
    return Vec3(x-v.getX(),y-v.getY(),z-v.getZ());
}

Vec3::~Vec3() = default;
