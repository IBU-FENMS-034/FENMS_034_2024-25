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
add_executable(Week_01 Week_01/src/week_01.cpp
        Week_03/include/QueueBasedStack.h)
add_executable(Week_01_analysis Week_01/src/empirical_analysis.cpp)
add_executable(Week_01_lab
        Week_01/include/Student.h
        Week_01/include/StudentList.h
        Week_01/src/Student.tpp
        Week_01/src/StudentList.tpp
        Week_01/src/student_test.cpp
)
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

# Week 2 task
add_executable(Week_02_labtest
        Week_02/test/week_02_labtest.cpp
        Week_02/include/DoubleNode.h
        Week_02/include/DoublyLinkedList.h
        Week_02/include/DoublyLinkedList.tpp
)
target_link_libraries(Week_02_labtest PRIVATE doctest::doctest)

# Week 3
add_executable(Week_03 Week_03/src/week_03.cpp)
add_executable(Week_03_test Week_03/test/week_03_test.cpp)
add_library(Week_03_lib INTERFACE
        Week_03/include/Node.h
        Week_03/include/Queue.h
        Week_03/include/Stack.h
        Week_03/include/Queue.tpp
        Week_03/include/Stack.tpp)
target_link_libraries(Week_03 PRIVATE Week_03_lib)
target_link_libraries(Week_03_test PRIVATE Week_03_lib doctest::doctest)

# Week 4
add_executable(Week_04 Week_04/src/week_04.cpp)
add_executable(Week_04_analysis Week_04/src/empirical_analysis.cpp)
add_executable(Week_04_test Week_04/test/week_04_test.cpp)
add_library(Week_04_lib INTERFACE
        Week_04/include/Search.h
        Week_04/include/Sort.h
        Week_04/include/Student.h
        Week_04/include/Sort.tpp
        Week_04/include/Search.tpp)
target_link_libraries(Week_04 PRIVATE Week_04_lib)
target_link_libraries(Week_04_analysis PRIVATE Week_04_lib)
target_link_libraries(Week_04_test PRIVATE Week_04_lib doctest::doctest)

# Week 4 task
add_executable(Week_04_labtest
        Week_04/test/week_04_labtest.cpp
        Week_04/include/IPAddress.h
        Week_04/include/FileUtils.h
        Week_04/include/IPSearch.h
        Week_04/src/FileUtils.cpp
        Week_04/src/IPSearch.cpp
)
target_link_libraries(Week_04_labtest PRIVATE doctest::doctest)

# Week 5
add_executable(Week_05 Week_05/src/week_05.cpp)
add_executable(Week_05_analysis Week_05/src/empirical_analysis.cpp)
add_executable(Week_05_test Week_05/test/week_05_test.cpp)
add_library(Week_05_lib INTERFACE
        Week_05/include/ElementarySort.h
        Week_05/include/ElementarySort.tpp)
target_link_libraries(Week_05 PRIVATE Week_05_lib)
target_link_libraries(Week_05_analysis PRIVATE Week_05_lib)
target_link_libraries(Week_05_test PRIVATE Week_05_lib doctest::doctest)

# Week 5 task
add_executable(Week_05_labtest
        Week_05/test/week_05_labtest.cpp
        Week_05/include/BinaryInsertionSort.h
        Week_05/include/BinaryInsertionSort.tpp
)
target_link_libraries(Week_05_labtest PRIVATE doctest::doctest)

# Week 6
add_executable(Week_06 Week_06/src/week_06.cpp)
add_executable(Week_06_analysis Week_06/src/empirical_analysis.cpp)
add_executable(Week_06_test Week_06/test/week_06_test.cpp)
add_library(Week_06_lib INTERFACE
        Week_06/include/MergeSort.h
        Week_06/include/MergeSort.tpp)
target_link_libraries(Week_06 PRIVATE Week_06_lib)
target_link_libraries(Week_06_analysis PRIVATE Week_06_lib)
target_link_libraries(Week_06_test PRIVATE Week_06_lib doctest::doctest)

# Week 6 task
add_executable(Week_06_labtest
        Week_06/test/week_06_labtest.cpp
        Week_06/include/TimSort.h
        Week_06/include/TimSort.tpp
)
target_link_libraries(Week_06_labtest PRIVATE doctest::doctest)

# Week 7
add_executable(Week_07 Week_07/src/week_07.cpp)
add_executable(Week_07_analysis Week_07/src/empirical_analysis.cpp)
add_executable(Week_07_test Week_07/test/week_07_test.cpp)
add_library(Week_07_lib INTERFACE
        Week_07/include/QuickSort.h
        Week_07/include/QuickSort.tpp)
target_link_libraries(Week_07 PRIVATE Week_07_lib)
target_link_libraries(Week_07_analysis INTERFACE Week_07_lib)
target_link_libraries(Week_07_test PRIVATE Week_07_lib doctest::doctest)

# Week 7 task
add_executable(Week_07_labtest
        Week_07/test/week_07_labtest.cpp
        Week_07/include/DualPivotQuickSort.h
        Week_07/include/DualPivotQuickSort.tpp)
target_link_libraries(Week_07_labtest PRIVATE doctest::doctest)

# Week 8
add_executable(Week_08 Week_08/src/week_08.cpp)
add_executable(Week_08_analysis Week_08/src/empirical_analysis.cpp)
add_executable(Week_08_test Week_08/test/week_08_test.cpp)
add_library(Week_08_lib INTERFACE
        Week_08/include/NonComparisonSort.h
        Week_08/include/NonComparisonSort.tpp)
target_link_libraries(Week_08 PRIVATE Week_08_lib)
target_link_libraries(Week_08_analysis PRIVATE Week_08_lib)
target_link_libraries(Week_08_test PRIVATE Week_08_lib doctest::doctest)