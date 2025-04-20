//
// Created by aldin on 11/02/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/NonComparisonSort.h"
#include <doctest/doctest.h>

TEST_CASE("Radix sort") {
    SUBCASE("Sorting an array of integers") {
        int arr[] = {3, 2, 9, 1, 5, 6};
        int expected[] = {1, 2, 3, 5, 6, 9};
        constexpr int size = sizeof(arr) / sizeof(int);

        NonComparisonSort::radix_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an already sorted array") {
        int arr[] = {1, 2, 3, 4, 5};
        int expected[] = {1, 2, 3, 4, 5};
        constexpr int size = sizeof(arr) / sizeof(int);

        NonComparisonSort::radix_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an array with duplicate values") {
        int arr[] = {4, 4, 2, 2, 1, 1};
        int expected[] = {1, 1, 2, 2, 4, 4};
        constexpr int size = sizeof(arr) / sizeof(int);

        NonComparisonSort::radix_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }
}

TEST_CASE("Counting sort") {
    SUBCASE("Sorting an array of integers") {
        int arr[] = {3, 2, 9, 1, 5, 6};
        int expected[] = {1, 2, 3, 5, 6, 9};
        constexpr int size = sizeof(arr) / sizeof(int);

        NonComparisonSort::counting_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an already sorted array") {
        int arr[] = {1, 2, 3, 4, 5};
        int expected[] = {1, 2, 3, 4, 5};
        constexpr int size = sizeof(arr) / sizeof(int);

        NonComparisonSort::counting_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an array with duplicate values") {
        int arr[] = {4, 4, 2, 2, 1, 1};
        int expected[] = {1, 1, 2, 2, 4, 4};
        constexpr int size = sizeof(arr) / sizeof(int);

        NonComparisonSort::counting_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }
}