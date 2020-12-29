//
// Created by 张向辉 on 2020/12/28.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include "Vec3.h"

class Camera {
private:
    Vec3 position, direction, right, down;
public:
    Camera();
    Camera(const Vec3&,const Vec3&,const Vec3&,const Vec3&);

    ~Camera();

    const Vec3 &getPosition() const;

    const Vec3 &getDirection() const;

    const Vec3 &getRight() const;

    const Vec3 &getDown() const;

};


#endif //RAYTRACING_CAMERA_H
