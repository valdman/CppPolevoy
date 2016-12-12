cmake_minimum_required(VERSION 3.6)
project(ssv_demo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

add_executable(ssv_demo ${SOURCE_FILES})
target_link_libraries(ssv_demo ssvdata)