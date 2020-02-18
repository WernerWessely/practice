cmake_minimum_required(VERSION 3.0)

set(TARGET_NAME ut)
project(${TARGET_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${TARGET_NAME} slist.cpp ut.cpp)

target_include_directories(${TARGET_NAME} PRIVATE ../catch2)

if(MSVC)
  target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()