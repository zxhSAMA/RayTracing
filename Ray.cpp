//
// Created by 张向辉 on 2020/12/28.
//

#include "Ray.h"

Ray::Ray():ori(Vec3(0,0,0)),dri(Vec3(0,0,0)){}

Ray::Ray(const Vec3& o, const Vec3& d):ori(o),dri(d){}

Ray::~Ray() = default;

const Vec3 &Ray::getOri() const {
    return ori;
}

const Vec3 &Ray::getDri() const {
    return dri;
}
