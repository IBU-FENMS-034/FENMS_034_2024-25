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
add_executable(Week_01_analysis Week_01/src/empirical_analysis.cpp)
add_library(Week_01_lib
        Week_01/include/Fibonacci.h
        Week_01/include/MemoryPerf.h
        Week_01/src/Fibonacci.cpp
)
target_link_libraries(Week_01 PRIVATE Week_01_lib)
target_link_libraries(Week_01_analysis PRIVATE Week_01_lib)

# Week 2
add_executable(Week_02 Week_02/src/week_02.cpp)
add_executable(Week_02_analysis Week_02/src/empirical_analysis.cpp)
add_executable(Week_02_test Week_02/test/week_02_test.cpp)
add_library(Week_02_lib INTERFACE
        Week_02/include/LinkedList.h
        Week_02/include/LinkedList.tpp
        Week_02/include/Node.h
)
target_link_libraries(Week_02 PRIVATE Week_02_lib)
target_link_libraries(Week_02_analysis PRIVATE Week_02_lib)
target_link_libraries(Week_02_test PRIVATE Week_02_lib doctest::doctest)