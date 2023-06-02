cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(jlox-cpp VERSION 0.1.0)

#set c++ standard to c++ 23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set compile flags to generate extra warning messages
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -O3 -flto -DNDEBUG")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#locate conan generated config files from build folder
list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_BINARY_DIR}")

#find the gtest package
find_package(GTest REQUIRED)
#include all headers and source files
include_directories(${GTEST_INCLUDE_DIRS})

#include test directory
include_directories(tests)

#link all source files to project
file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(jlox-cpp ${SOURCES})
#link gtest to main project
target_link_libraries(jlox-cpp GTest::GTest GTest::Main)
