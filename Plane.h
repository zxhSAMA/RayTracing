//
// Created by 张向辉 on 2020/12/29.
//

#ifndef RAYTRACING_PLANE_H
#define RAYTRACING_PLANE_H

#include "Object.h"
#include "Vec3.h"
#include "Color.h"
#include "Ray.h"

class Plane : public Object {
private:
    Vec3 normal;
    double distance;
    Color color;
public:
    Plane();

    Plane(const Vec3 &normal, double distance, const Color &color);

    const Vec3 &getNormal() const;

    double getDistance() const;

    const Color &getColor1() const;

    Vec3 get_normal_at(const Vec3&) const;

    double find_intersection(const Ray& ray);
};


#endif //RAYTRACING_PLANE_H
