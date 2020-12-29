//
// Created by 张向辉 on 2020/12/25.
//

#ifndef RAYTRACING_BMPWRITER_H
#define RAYTRACING_BMPWRITER_H

#include <fstream>

struct RGB{
    double r;
    double g;
    double b;
};

class BmpWriter {
private:
    int weight;
    int height;
    int dpi; //dots per inch
    RGB *pixel_data;

public:
    BmpWriter();
    BmpWriter(int,int);
    BmpWriter(int,int,int);
    ~BmpWriter();
    int get_size() const;
    void set_pixel_data(RGB*);
    void save(const char*);
};


#endif //RAYTRACING_BMPWRITER_H
