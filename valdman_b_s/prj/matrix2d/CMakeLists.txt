cmake_minimum_required(VERSION 3.6)
project(matrix2d)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Source/matrix2d.cpp Headers/matrix2d.h Source/serializer.cpp Headers/serializer.h)
add_executable(matrix2d ${SOURCE_FILES})