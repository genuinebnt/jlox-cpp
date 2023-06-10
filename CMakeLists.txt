cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(jlox-cpp VERSION 0.1.0)

#set c++ standard to c++ 23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set compile flags to generate extra warning messages
set(CMAKE_CXX_FLAGS "-Wall -DNDEBUG")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#locate conan generated config files from build folder
list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_BINARY_DIR}")

#include src directory
add_subdirectory(src)

enable_testing()

#include test directory
add_subdirectory(tests)