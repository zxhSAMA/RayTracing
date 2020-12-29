//
// Created by 张向辉 on 2020/12/29.
//

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "Object.h"
#include "Vec3.h"
#include "Color.h"

class Sphere : public Object{
private:
    Vec3 center;
    double radius;
    Color color;
public:
    Sphere();

    Sphere(const Vec3 &center, double radius, const Color &color);

    const Vec3 &getCenter() const;

    double getRadius() const;

    const Color &getColor() const;

    virtual ~Sphere();
};


#endif //RAYTRACING_SPHERE_H
