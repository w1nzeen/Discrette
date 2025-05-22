cmake_minimum_required(VERSION 3.30)
project(lab6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab6
    Graph.cpp
    Graph.h
    main.cpp)
