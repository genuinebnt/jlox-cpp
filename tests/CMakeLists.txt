cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(jlox-cpp-tests VERSION 0.1.0)

# Dependencies
# If dependencies are managed with conan, we prepend the current build folder
# to the CMake module path, where CMake looks for dependencies.
if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/conaninfo.txt)
    list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_BINARY_DIR}")
endif()
#find the gtest package
find_package(GTest REQUIRED)
#include all headers and source files
include_directories(${CMAKE_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE TESTS *.cpp *.h)

add_executable(jlox-cpp-tests ${TESTS})

target_link_libraries(jlox-cpp-tests PUBLIC jlox-cpp-lib GTest::GTest GTest::Main)
