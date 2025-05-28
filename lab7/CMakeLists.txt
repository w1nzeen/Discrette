cmake_minimum_required(VERSION 3.30)
project(lab7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab7
    Constants.h
    Dijkstra.cpp
    Dijkstra.h
    Floyd.cpp
    Floyd.h
    main.cpp)
