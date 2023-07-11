cmake_minimum_required(VERSION 3.10..3.25)

project(Graph)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(run ./Graph/dfs.cpp ./Graph/dfs.hpp ./main.cpp)
