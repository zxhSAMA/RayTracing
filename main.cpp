#include <iostream>
#include "BmpWriter.h"
#include "Vec3.h"
#include "Ray.h"
#include "Color.h"
#include "Light.h"
#include "Sphere.h"
#include "Plane.h"

int main(){
    std::cout<<"Rendering..."<<std::endl;

    Vec3 norm_x(1,0,0);
    Vec3 norm_y(0,1,0);
    Vec3 norm_z(0,0,1);

    Vec3 cam_pos(-3,-1.5,4);
    Vec3 look_at(0,0,0);
    Vec3 cam_dir = cam_pos.vec_minus(look_at).negative().normalize();
    Vec3 cam_right = norm_y.cross_product(cam_dir).normalize();
    Vec3 cam_down = cam_right.cross_product(cam_dir).normalize();


    std::cout<<"pos : "<<cam_pos<<std::endl;
    std::cout<<"dir : "<<cam_dir<<std::endl;
    std::cout<<"rig : "<<cam_right<<std::endl;
    std::cout<<"dow : "<<cam_down<<std::endl;


    Color white(1.0,1.0,1.0,0.0);
    Color pretty_green(0.1255, 0.6980, 0.6667, 0.3);
    Color pretty_yellow(1.0000, 0.8941, 0.7098, 0.0);
    Color grey(0.5, 0.5, 0.5, 0.0);
    Color black(0.0,0.0,0.0,0.0);

    Vec3 light_position(-7,10,-10);
    Light scene_light(light_position,white);

    Sphere scene_sphere(look_at,1.0,pretty_green);
    Plane scene_plane(norm_y, -1.0, pretty_yellow);

    int weight = 1920;
    int height = 1080;
    BmpWriter bw(weight,height);
    RGB *pixel = new RGB[bw.get_size()];
    for (int x = 0; x < weight; ++x) {
        for (int y = 0; y < height; ++y) {
            int index = y*weight+x;
            if ((x>320&&x<(1920-320))&&(y>180&&y<(1080-180))){
                pixel[index].r = 0.1255;
                pixel[index].g = 0.6980;
                pixel[index].b = 0.6667;
            }else{
                pixel[index].r = 1.0000;
                pixel[index].g = 0.8941;
                pixel[index].b = 0.7098;
            }
        }
    }

    bw.set_pixel_data(pixel);
    bw.save("scene.bmp");
    delete[] pixel;
    return 0;
}