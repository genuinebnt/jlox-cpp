cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(jlox-cpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -O3 -flto -DNDEBUG")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(jlox-cpp ${SOURCES})