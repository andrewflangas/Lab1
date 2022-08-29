cmake_minimum_required(VERSION 3.22)
project(Lab1 C)

set(CMAKE_C_STANDARD 99)

add_library(Lab1 include/mymalloc.h src/mymalloc.c)

target_include_directories(Lab1
        PUBLIC include
        PUBLIC src)