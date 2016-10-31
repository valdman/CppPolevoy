cmake_minimum_required(VERSION 3.6)

project(arrstack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SOURCE_FILES main.cpp arrstack.cpp arrstack.h)
add_executable(arrstack ${SOURCE_FILES})