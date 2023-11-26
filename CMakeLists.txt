cmake_minimum_required(VERSION 3.10.2)

project(hierarchical-zbuffer)
find_package(GLUT REQUIRED)

include_directories(include)

add_executable(main src/main.cpp)

target_link_libraries(main ${GLUT_LIBRARIES})
