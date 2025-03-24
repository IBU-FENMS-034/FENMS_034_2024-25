//
// Created by aldin on 14/02/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/Search.h"
#include "../include/Sort.h"
#include <doctest/doctest.h>

TEST_CASE("Linear search") {
    SUBCASE("Searching for an element present in an array of integers") {
        int arr[] = {5, 3, 8, 1, 9};
        constexpr size_t size = sizeof(arr) / sizeof(arr[0]);
        int key = 8;
        int expected_index = 2; // First occurrence index.
        int index = Search::linear_search(arr, size, key);
        CHECK_EQ(expected_index, index);
    }

    SUBCASE("Searching for an element not present in an array") {
        int arr[] = {5, 3, 8, 1, 9};
        constexpr size_t size = sizeof(arr) / sizeof(arr[0]);
        int key = 7;
        int index = Search::linear_search(arr, size, key);
        CHECK_EQ(-1, index);  // Assuming -1 is returned when key is not found.
    }

    SUBCASE("Searching in an array with duplicate values") {
        int arr[] = {1, 2, 3, 2, 4};
        constexpr size_t size = sizeof(arr) / sizeof(arr[0]);
        int key = 2;
        int index = Search::linear_search(arr, size, key);
        // Expecting the first occurrence.
        CHECK_EQ(1, index);
    }

    SUBCASE("Searching in an array of strings") {
        std::string arr[] = {"apple", "banana", "cherry", "date"};
        constexpr size_t size = sizeof(arr) / sizeof(arr[0]);
        std::string key = "cherry";
        int index = Search::linear_search(arr, size, key);
        CHECK_EQ(2, index);
    }
}

TEST_CASE("Binary search") {
    SUBCASE("Searching for an element present in a sorted array of integers") {
        int arr[] = {1, 3, 5, 7, 9};
        constexpr size_t size = sizeof(arr) / sizeof(arr[0]);
        int key = 7;
        int expected_index = 3;
        int index = Search::binary_search(arr, size, key);
        CHECK_EQ(expected_index, index);
    }

    SUBCASE("Searching for an element not present in a sorted array") {
        int arr[] = {1, 3, 5, 7, 9};
        constexpr size_t size = sizeof(arr) / sizeof(arr[0]);
        int key = 6;
        int index = Search::binary_search(arr, size, key);
        CHECK_EQ(-1, index);
    }

    SUBCASE("Searching in a sorted array with duplicate values") {
        int arr[] = {1, 2, 2, 2, 3, 4};
        constexpr size_t size = sizeof(arr) / sizeof(arr[0]);
        int key = 2;
        int index = Search::binary_search(arr, size, key);
        // With duplicates, binary search might return any index containing the key.
        // We'll verify that the returned index holds the searched key.
        CHECK(index >= 0);
        CHECK(arr[index] == key);
    }

    SUBCASE("Searching in a sorted array of strings") {
        std::string arr[] = {"apple", "banana", "cherry", "date"};
        constexpr size_t size = sizeof(arr) / sizeof(arr[0]);
        std::string key = "date";
        int expected_index = 3;
        int index = Search::binary_search(arr, size, key);
        CHECK_EQ(expected_index, index);
    }
}

TEST_CASE("Bubble sort") {
    SUBCASE("Sorting an array of integers") {
        int arr[] = {3, -2, 9, -1, 5, 6};
        int expected[] = {-2, -1, 3, 5, 6, 9};
        constexpr int size = sizeof(arr) / sizeof(int);

        Sort::bubble_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an already sorted array") {
        int arr[] = {1, 2, 3, 4, 5};
        int expected[] = {1, 2, 3, 4, 5};
        constexpr int size = sizeof(arr) / sizeof(int);

        Sort::bubble_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an array of floating point numbers") {
        double arr[] = {3.2, 1.5, 4.8, 2.9};
        double expected[] = {1.5, 2.9, 3.2, 4.8};
        constexpr int size = sizeof(arr) / sizeof(double);

        Sort::bubble_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an array of strings") {
        std::string arr[] = {"hi", "bye", "hello", "world", "i", "love", "c++"};
        std::string expected[] = {"bye", "c++", "hello", "hi", "i", "love", "world"};
        constexpr int size = sizeof(arr) / sizeof(std::string);

        Sort::bubble_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting an array with duplicate values") {
        int arr[] = {4, 4, 2, 2, 1, 1};
        int expected[] = {1, 1, 2, 2, 4, 4};
        constexpr int size = sizeof(arr) / sizeof(int);

        Sort::bubble_sort(arr, size);
        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }
}
