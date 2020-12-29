CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

PROJECT(RayTracing VERSION 0.0.1)

SET(CMAKE_CXX_COMPILER "g++")

add_definitions(-std=c++11)

SET(SRC_LIST main.cpp BmpWriter.cpp BmpWriter.h Vec3.cpp Vec3.h Ray.cpp Ray.h Camera.cpp Camera.h Color.cpp Color.h Light.cpp Light.h Sphere.cpp Sphere.h Object.cpp Object.h Plane.cpp Plane.h)

ADD_EXECUTABLE(RayTracing ${SRC_LIST})