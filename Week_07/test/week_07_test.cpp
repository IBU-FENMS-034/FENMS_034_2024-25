//
// Created by aldin on 11/02/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/QuickSort.h"
#include "../include/DualPivotQuickSort.h"
#include <doctest/doctest.h>


TEST_CASE("Quick sort") {
    SUBCASE("Sorting an array of integers") {
        int arr[] = {3, -2, 9, -1, 5, 6};
        int expected[] = {-2, -1, 3, 5, 6, 9};
        constexpr int size = sizeof(arr) / sizeof(int);

        QuickSort::quick_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an already sorted array") {
        int arr[] = {1, 2, 3, 4, 5};
        int expected[] = {1, 2, 3, 4, 5};
        constexpr int size = sizeof(arr) / sizeof(int);

        QuickSort::quick_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an array of floating point numbers") {
        double arr[] = {3.2, 1.5, 4.8, 2.9};
        double expected[] = {1.5, 2.9, 3.2, 4.8};
        constexpr int size = sizeof(arr) / sizeof(double);

        QuickSort::quick_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an array of strings") {
        std::string arr[] = {"hi", "bye", "hello", "world", "i", "love", "c++"};
        std::string expected[] = {"bye", "c++", "hello", "hi", "i", "love", "world"};
        constexpr int size = sizeof(arr) / sizeof(std::string);

        QuickSort::quick_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an array with duplicate values") {
        int arr[] = {4, 4, 2, 2, 1, 1};
        int expected[] = {1, 1, 2, 2, 4, 4};
        constexpr int size = sizeof(arr) / sizeof(int);

        QuickSort::quick_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }
}

TEST_CASE("Dual-pivot quick sort") {
    SUBCASE("Sorting an array of integers") {
        int arr[] = {3, -2, 9, -1, 5, 6};
        int expected[] = {-2, -1, 3, 5, 6, 9};
        constexpr int size = sizeof(arr) / sizeof(int);

        DualPivotQuickSort::quick_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an already sorted array") {
        int arr[] = {1, 2, 3, 4, 5};
        int expected[] = {1, 2, 3, 4, 5};
        constexpr int size = sizeof(arr) / sizeof(int);

        DualPivotQuickSort::quick_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an array of floating point numbers") {
        double arr[] = {3.2, 1.5, 4.8, 2.9};
        double expected[] = {1.5, 2.9, 3.2, 4.8};
        constexpr int size = sizeof(arr) / sizeof(double);

        DualPivotQuickSort::quick_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an array of strings") {
        std::string arr[] = {"hi", "bye", "hello", "world", "i", "love", "c++"};
        std::string expected[] = {"bye", "c++", "hello", "hi", "i", "love", "world"};
        constexpr int size = sizeof(arr) / sizeof(std::string);

        DualPivotQuickSort::quick_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an array with duplicate values") {
        int arr[] = {4, 4, 2, 2, 1, 1};
        int expected[] = {1, 1, 2, 2, 4, 4};
        constexpr int size = sizeof(arr) / sizeof(int);

        DualPivotQuickSort::quick_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }
}