//
// Created by 张向辉 on 2020/12/28.
//

#ifndef RAYTRACING_COLOR_H
#define RAYTRACING_COLOR_H


class Color {
private:
    double red,green,blue,alpha;
public:
    Color();
    Color(double, double, double, double);
    virtual ~Color();

    double getRed() const;

    double getGreen() const;

    double getBlue() const;

    double getAlpha() const;

    void setRed(double red);

    void setGreen(double g);

    void setBlue(double b);

    void setAlpha(double a);
};


#endif //RAYTRACING_COLOR_H
