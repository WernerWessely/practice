cmake_minimum_required(VERSION 3.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

set(TARGET_NAME ut)
project(${TARGET_NAME} CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(${TARGET_NAME} slist.cpp ut.cpp)

target_link_libraries(${TARGET_NAME} ${CONAN_LIBS})

if(MSVC)
  target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
  add_test(NAME ${TARGET_NAME} COMMAND ./${TARGET_NAME})
endif()

conan_basic_setup()
