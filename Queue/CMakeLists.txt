cmake_minimum_required(VERSION 3.22)

project(Queue)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(Queue Queue.h Queue.cpp main.cpp)


