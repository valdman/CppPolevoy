cmake_minimum_required(VERSION 3.6)
project(ssv)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS)

set(SOURCE_FILES
    main.cpp
        ssvdata.cpp
        ssvdata.h)

add_executable(ssv ${SOURCE_FILES})