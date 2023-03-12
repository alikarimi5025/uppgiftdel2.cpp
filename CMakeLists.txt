cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(FileCrawler)

## Set your file here
add_executable(FileCrawler del2.cpp)
