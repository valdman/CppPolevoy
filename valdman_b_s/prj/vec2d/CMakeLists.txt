cmake_minimum_required(VERSION 3.6)
project(vec2d)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    testVector.cpp
    vec2d.cpp
    vec2d.h)

add_executable(vec2d ${SOURCE_FILES})