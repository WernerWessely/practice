cmake_minimum_required(VERSION 3.0)
project(vector)

add_definitions(-std=c++11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

set(SOURCE_FILES main.cpp wv.cpp)
add_executable(vector ${SOURCE_FILES})