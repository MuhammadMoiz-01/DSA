cmake_minimum_required(VERSION 3.25)
project(CppProjects)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CppProjects
        Node.cpp
        Node.hpp main.cpp)
