cmake_minimum_required(VERSION 3.22)
project(Lab1 C)

set(CMAKE_C_STANDARD 99)

set(SOURCES src/mymalloc.c src/main.c include/mymalloc.h src/main.c)

add_executable(Lab1 ${SOURCES})

target_include_directories(Lab1
        PUBLIC include
        PUBLIC src)