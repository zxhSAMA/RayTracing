//
// Created by 张向辉 on 2020/12/28.
//

#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include "Vec3.h"

class Ray {
private:
    Vec3 ori,dri;
public:
    Ray();
    Ray(const Vec3&,const Vec3&);
    ~Ray();

    const Vec3 &getOri() const;

    const Vec3 &getDri() const;
};


#endif //RAYTRACING_RAY_H
