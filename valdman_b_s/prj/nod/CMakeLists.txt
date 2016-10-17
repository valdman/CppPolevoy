cmake_minimum_required(VERSION 3.6)
project(nod)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    nod.cpp)

add_executable(nod ${SOURCE_FILES})