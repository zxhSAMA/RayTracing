//
// Created by 张向辉 on 2020/12/25.
//

#include "BmpWriter.h"
#include <iostream>
#include <iomanip>
#include <cmath>

BmpWriter::BmpWriter() {
    this->weight = 0;
    this->height = 0;
    this->dpi = 0;
    this->pixel_data = nullptr;
}

BmpWriter::BmpWriter(int _w, int _h) {
    this->weight = _w;
    this->height = _h;
    this->dpi = 72;
    this->pixel_data = nullptr;
}

BmpWriter::BmpWriter(int _w, int _h, int _dpi) {
    this->weight = _w;
    this->height = _h;
    this->dpi = _dpi;
    this->pixel_data = nullptr;
}

BmpWriter::~BmpWriter() = default;

void BmpWriter::save(const char *file_name) {
    int pixel_num = this->height* this->weight;
    int bitmap_size = 4*pixel_num;
    int header_size = 54;
    int file_size = header_size+bitmap_size;
    int resolution = 4096; //Pixels per meter
    unsigned char bmp_file_header[14] = {0};

    bmp_file_header[ 0] = (unsigned char)('B');
    bmp_file_header[ 1] = (unsigned char)('M');
    bmp_file_header[ 2] = (unsigned char)(file_size);
    bmp_file_header[ 3] = (unsigned char)(file_size >> 8);
    bmp_file_header[ 4] = (unsigned char)(file_size >> 16);
    bmp_file_header[ 5] = (unsigned char)(file_size >> 24);
    bmp_file_header[10] = (unsigned char)(header_size);
    bmp_file_header[11] = (unsigned char)(header_size >> 8);
    bmp_file_header[12] = (unsigned char)(header_size >> 16);
    bmp_file_header[13] = (unsigned char)(header_size >> 24);

    unsigned char bmp_info_header[40] = {0};
    //            {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,8,0};
    bmp_info_header[ 0] = (unsigned char)(40);

    bmp_info_header[ 4] = (unsigned char)(this->weight);
    bmp_info_header[ 5] = (unsigned char)(this->weight >> 8);
    bmp_info_header[ 6] = (unsigned char)(this->weight >> 16);
    bmp_info_header[ 7] = (unsigned char)(this->weight >> 24);

    bmp_info_header[ 8] = (unsigned char)(this->height);
    bmp_info_header[ 9] = (unsigned char)(this->height >> 8);
    bmp_info_header[10] = (unsigned char)(this->height >> 16);
    bmp_info_header[11] = (unsigned char)(this->height >> 24);

    bmp_info_header[12] = (unsigned char)(1);
    bmp_info_header[14] = (unsigned char)(24);

    bmp_info_header[21] = (unsigned char)(bitmap_size);
    bmp_info_header[22] = (unsigned char)(bitmap_size >> 8);
    bmp_info_header[23] = (unsigned char)(bitmap_size >> 16);
    bmp_info_header[24] = (unsigned char)(bitmap_size >> 24);

//    x resolution
    bmp_info_header[25] = (unsigned char)(resolution);
    bmp_info_header[26] = (unsigned char)(resolution >> 8);
    bmp_info_header[27] = (unsigned char)(resolution >> 16);
    bmp_info_header[28] = (unsigned char)(resolution >> 24);

//    y resolution
    bmp_info_header[29] = (unsigned char)(resolution);
    bmp_info_header[30] = (unsigned char)(resolution >> 8);
    bmp_info_header[31] = (unsigned char)(resolution >> 16);
    bmp_info_header[32] = (unsigned char)(resolution >> 24);

    std::ofstream file;
    file.open(file_name, std::ios::binary | std::ios::out);
    file.write(reinterpret_cast<const char *>(bmp_file_header), sizeof(bmp_file_header));

//    for (unsigned char & i : bmp_file_header) {
//        std::cout<<"0x"<<std::hex<<std::setw(2)<<std::setfill('0')<<(int)i<<" ";
//    }
//    std::cout<<std::endl;

    file.write(reinterpret_cast<const char *>(bmp_info_header), sizeof(bmp_info_header));
//    for (unsigned char & i : bmp_info_header) {
//        std::cout<<"0x"<<std::hex<<std::setw(2)<<std::setfill('0')<<(int)i<<" ";
//    }
//    std::cout<<std::endl;

    for (int i = 0; i < pixel_num; ++i) {
        unsigned char color[3] = {(unsigned char)floor(255*(this->pixel_data[i].b)),(unsigned char)floor(255*(this->pixel_data[i].g)),(unsigned char)floor(255*(this->pixel_data[i].r))};
//        std::cout<<"pic "<<i<<" : "<<pixel_data[i].b<<" "<<pixel_data[i].g<<" "<<pixel_data[i].r<<std::endl;
        file.write(reinterpret_cast<const char *>(color), sizeof(color));
    }
    file.close();

//    std::cout<<"pic bit : "<<std::endl;


//    std::ifstream bmpf;
//    bmpf.open(file_name,std::ios::binary|std::ios::in);
//    unsigned char read_bit;
//    bmpf >> std::noskipws;
//    while (bmpf>>read_bit){
//        std::cout<<"0x"<<std::hex<<std::setw(2)<<std::setfill('0')<<(int)read_bit<<" ";
//    }

}

void BmpWriter::set_pixel_data(RGB * data) {
    this->pixel_data = data;
}

int BmpWriter::get_size() const {
    return this->height * this->weight;
}

