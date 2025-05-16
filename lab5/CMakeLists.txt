cmake_minimum_required(VERSION 3.30)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab5
    Converter.cpp
    Converter.h
    main.cpp)
