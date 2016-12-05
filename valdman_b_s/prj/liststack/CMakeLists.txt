cmake_minimum_required(VERSION 3.6)
project(liststack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra")

set(SOURCE_FILES main.cpp liststack.h)
add_executable(liststack ${SOURCE_FILES})