cmake_minimum_required(VERSION 3.30)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab2
    main.cpp
    Sort.cpp
    Sort.h)
