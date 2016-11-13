cmake_minimum_required(VERSION 3.6)
project(ssv)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Sources/ssv_service.cpp Headers/ssv_service.h Sources/ssv.cpp Headers/ssv.h Sources/row.cpp Headers/row.h)
add_executable(ssv ${SOURCE_FILES})