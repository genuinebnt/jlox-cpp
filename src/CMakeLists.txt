cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

#link all source files to project
file(GLOB_RECURSE SOURCES *.cpp *.h)
add_library(jlox-cpp-lib ${SOURCES})

add_executable(jlox-cpp main.cpp)

target_link_libraries(jlox-cpp PRIVATE jlox-cpp-lib)