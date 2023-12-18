cmake_minimum_required(VERSION 3.26)
project(projeto2_AED)

set(CMAKE_CXX_STANDARD 17)

add_executable(projeto2_AED main.cpp
        Graph.h
        Airports.cpp
        Graph.cpp
        Menu.cpp
        Read.h)
