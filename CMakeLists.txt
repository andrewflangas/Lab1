cmake_minimum_required(VERSION 3.22)
project(Lab1 C)

set(CMAKE_C_STANDARD 99)

add_library(Lab1 library.c mymalloc.h mymalloc.c)
