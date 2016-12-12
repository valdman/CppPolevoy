cmake_minimum_required(VERSION 3.6)
project(ssvdata)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -v)

add_library (ssvdata ssvdata.h ssvdata.cpp)
target_include_directories (ssvdata PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
