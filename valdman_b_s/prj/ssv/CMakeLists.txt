cmake_minimum_required(VERSION 3.6)
project(ssv)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-v")

set(SOURCE_FILES
    main.cpp
    ssv_service.cpp
    ssv_service.h)

add_executable(ssv ${SOURCE_FILES})