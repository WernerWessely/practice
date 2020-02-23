cmake_minimum_required(VERSION 3.0)

enable_testing()

set(TARGET_NAME ut)
project(${TARGET_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${TARGET_NAME} pqueue.cpp ut.cpp)

target_include_directories(${TARGET_NAME} PRIVATE ../catch2)

if(MSVC)
  target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
  add_test(NAME ${TARGET_NAME} COMMAND ./${TARGET_NAME})
endif()