cmake_minimum_required(VERSION 3.28)
project(FENMS_034_2024_25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch doctest
include(FetchContent)
FetchContent_Declare(
        doctest
        GIT_REPOSITORY https://github.com/doctest/doctest.git
        GIT_TAG v2.4.11  # Use the latest stable version
)
FetchContent_MakeAvailable(doctest)

# Enable testing
enable_testing()

# Week 1
add_executable(Week_01 Week_01/src/week_01.cpp)
add_library(Week_01_lib
        Week_01/include/Fibonacci.h
        Week_01/include/MemoryPerf.h
        Week_01/src/Fibonacci.cpp
)
target_link_libraries(Week_01 PRIVATE Week_01_lib)