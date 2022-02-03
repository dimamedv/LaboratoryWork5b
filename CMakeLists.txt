cmake_minimum_required(VERSION 3.21)
project(Laboratory_work_5b C)

set(CMAKE_C_STANDARD 11)

add_executable(Laboratory_work_5b main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h libs/data_structures/vectorVoid/vectorVoid.c libs/data_structures/vectorVoid/vectorVoid.h)

add_subdirectory(libs)

target_link_libraries(Laboratory_work_5b data_structures)