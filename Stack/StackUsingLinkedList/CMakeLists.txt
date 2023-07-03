cmake_minimum_required(VERSION 3.22)

project(ListStack)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(ListStack main.cpp stack_ll.cpp)


