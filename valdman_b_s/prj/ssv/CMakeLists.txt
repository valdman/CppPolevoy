cmake_minimum_required(VERSION 3.6)
project(ssv)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -v")

set(SOURCE_FILES main.cpp ssv_service.h ssv_service.cpp)
add_executable(ssv ${SOURCE_FILES})