//
// Created by aldin on 11/02/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/DualPivotQuickSort.h"
#include <doctest/doctest.h>

struct Student {
    const char* name;
    double gpa;

    Student(const char* name, const double gpa) : name(name), gpa(gpa) {}
    Student() = default;

    friend bool operator<(const Student &s1, const Student &s2) { return s1.gpa < s2.gpa; }
    friend bool operator>(const Student &s1, const Student &s2) { return operator<(s2, s1); }
    friend bool operator==(const Student &s1, const Student &s2) { return s1.gpa == s2.gpa; }
    friend bool operator!=(const Student &s1, const Student &s2) { return !operator==(s1, s2); }
    friend bool operator<=(const Student &s1, const Student &s2) { return !operator>(s1, s2); }
    friend bool operator>=(const Student &s1, const Student &s2) { return !operator<(s1, s2); }
};

TEST_CASE("Dual-pivot quick sort") {
    SUBCASE("Sorting a list of integers") {
        int arr[] = {5, -1, 7, 19, 3, 12, 4};
        int expected[] = {-1, 3, 4, 5, 7, 12, 19};
        constexpr int size = sizeof(arr) / sizeof(int);

        DualPivotQuickSort::quick_sort(arr, size);

        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting a list of doubles") {
        double arr[] = {3.14, -11.2, 43.6, 22.5, 7.12, 5.24, 66.2};
        double expected[] = {-11.2, 3.14, 5.24, 7.12, 22.5, 43.6, 66.2};
        constexpr int size = sizeof(arr) / sizeof(double);

        DualPivotQuickSort::quick_sort(arr, size);

        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting a list of chars") {
        char arr[] = {'y', 'm', 'a', 'c', 's', 'h', 'b'};
        char expected[] = {'a', 'b', 'c', 'h', 'm', 's', 'y'};
        constexpr int size = sizeof(arr) / sizeof(char);

        DualPivotQuickSort::quick_sort(arr, size);

        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting a list of strings") {
        std::string arr[] = {"qSiVYcEivp", "KHvpckFnVd", "RLbAwtkquH", "YmWxBwcHOZ", "NNAXXpPkpR", "hfRcldttwR", "lWtzsZCyPh"};
        std::string expected[] = {"KHvpckFnVd", "NNAXXpPkpR", "RLbAwtkquH", "YmWxBwcHOZ", "hfRcldttwR", "lWtzsZCyPh", "qSiVYcEivp"};
        constexpr int size = sizeof(arr) / sizeof(std::string);

        DualPivotQuickSort::quick_sort(arr, size);

        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting a list of objects") {
        Student arr[] = {
            Student("Student A", 6.3),
            Student("Student B", 9.93),
            Student("Student C", 5.76),
            Student("Student D", 8.21),
            Student("Student E", 7.74),
            Student("Student F", 10.0),
            Student("Student G", 9.2)
        };
        Student expected[] = {
            Student("Student C", 5.76),
            Student("Student A", 6.3),
            Student("Student E", 7.74),
            Student("Student D", 8.21),
            Student("Student G", 9.2),
            Student("Student B", 9.93),
            Student("Student F", 10.0)
        };
        constexpr int size = sizeof(arr) / sizeof(Student);

        DualPivotQuickSort::quick_sort(arr, size);

        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Testing dual partition") {
        int arr[] =  {17, 4, 9, 19, 3, -2, 12, 21, -5, 8, 7};
        constexpr int size = sizeof(arr) / sizeof(int);

        int* pivots = DualPivotQuickSort::partition(arr, 0, 10);

        CHECK_EQ(4, pivots[0]);
        CHECK_EQ(8, pivots[1]);

        for (int i = 0; i < pivots[0]; i++) {
            CHECK(arr[i] < arr[pivots[0]]);
        }
        for (int i = pivots[0]; i <= pivots[1]; i++) {
            CHECK(arr[i] >= arr[pivots[0]]);
            CHECK(arr[i] <= arr[pivots[1]]);
        }
        for (int i = pivots[1] + 1; i < size; i++) {
            CHECK(arr[i] > arr[pivots[1]]);
        }

        delete[] pivots;
    }
}