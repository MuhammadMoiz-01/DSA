cmake_minimum_required(VERSION 3.10..3.25)

project(Graph)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(DATA_DIR "./Graph/Data/")

add_executable(run ./Graph/dfs.cpp ./Graph/dfs.hpp ./main.cpp)

## Copy the data.txt file to the build directory
#configure_file(${CMAKE_SOURCE_DIR}/${DATA_DIR} ${CMAKE_BINARY_DIR}/${DATA_DIR} COPYONLY)

#Copy the data files present in the data directory to the build directory
file(GLOB DATA_FILES ${CMAKE_SOURCE_DIR}/${DATA_DIR}*.txt)
file(COPY ${DATA_FILES} DESTINATION ${CMAKE_BINARY_DIR}/${DATA_DIR})
