//
// Created by 张向辉 on 2020/12/28.
//

#ifndef RAYTRACING_LIGHT_H
#define RAYTRACING_LIGHT_H

#include "Vec3.h"
#include "Color.h"


class Light {
private:
    Vec3 position;
    Color color;
public:
    Light();
    Light(const Vec3 &position, const Color &color);
    virtual ~Light();

    const Vec3 &getPosition() const;

    const Color &getColor() const;

};


#endif //RAYTRACING_LIGHT_H
