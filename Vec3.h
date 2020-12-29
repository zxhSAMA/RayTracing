//
// Created by 张向辉 on 2020/12/28.
//

#ifndef RAYTRACING_VEC3_H
#define RAYTRACING_VEC3_H

#include <iostream>

class Vec3 {
private:
    double x,y,z;
public:
    Vec3();
    Vec3(double ,double ,double );
    ~Vec3();

    double getX() const;

    double getY() const;

    double getZ() const;

    double magnitude() const;

    Vec3 normalize() const;

    Vec3 negative() const;

    double dot_product(const Vec3 &v) const;

    Vec3 cross_product(const Vec3 &v) const;

    Vec3 vec_add(const Vec3 &v) const;

    Vec3 vec_mult(double scalar) const;

    Vec3 vec_minus(const Vec3 &v) const;

    friend std::ostream &operator<<(std::ostream &ost,Vec3 &v);
};


#endif //RAYTRACING_VEC3_H
