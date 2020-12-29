//
// Created by 张向辉 on 2020/12/29.
//

#ifndef RAYTRACING_OBJECT_H
#define RAYTRACING_OBJECT_H

#include "Color.h"

class Object {
private:
    Color color;
public:
    Object();

    const Color &getColor() const;

    double find_intersection();
};


#endif //RAYTRACING_OBJECT_H
