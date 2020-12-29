//
// Created by 张向辉 on 2020/12/28.
//

#include "Color.h"

Color::Color() : red(0.5),green(0.5),blue(0.5),alpha(0.5) {}

Color::Color(double r, double g, double b, double a) : red(r), green(g), blue(b), alpha(a) {}

double Color::getRed() const {
    return red;
}

double Color::getGreen() const {
    return green;
}

double Color::getBlue() const {
    return blue;
}

double Color::getAlpha() const {
    return alpha;
}

void Color::setRed(double red) {
    Color::red = red;
}

void Color::setGreen(double g) {
    Color::green = g;
}

void Color::setBlue(double b) {
    Color::blue = b;
}

void Color::setAlpha(double a) {
    Color::alpha = a;
}

Color::~Color() = default;
