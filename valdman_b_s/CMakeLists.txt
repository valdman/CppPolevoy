cmake_minimum_required(VERSION 3.6)
project(valdman_b_s)

set(CMAKE_CXX_STANDARD 11)

include_directories("./prj/interfaces")

add_subdirectory("./prj/arrstack")
add_subdirectory("./prj/complex")
add_subdirectory("./prj/liststack")
add_subdirectory("./prj/matrix2d")
add_subdirectory("./prj/nod")
add_subdirectory("./prj/rational")
add_subdirectory("./prj/ssv")
add_subdirectory("./prj/vec2d")
add_subdirectory("./prj/vector")