//
// Created by aldin on 14/02/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/TimSort.h"
#include <doctest/doctest.h>
#include <string>

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

TEST_CASE("Tim sort") {
    SUBCASE("Sorting a list of integers") {
        int arr[] = {5, -1, 7, 19, 3, 12, 4};
        int expected[] = {-1, 3, 4, 5, 7, 12, 19};
        constexpr int size = sizeof(arr) / sizeof(int);

        TimSort::sort(arr, size, 4);

        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting a list of doubles") {
        double arr[] = {3.14, -11.2, 43.6, 22.5, 7.12, 5.24, 66.2};
        double expected[] = {-11.2, 3.14, 5.24, 7.12, 22.5, 43.6, 66.2};
        constexpr int size = sizeof(arr) / sizeof(double);

        TimSort::sort(arr, size, 4);

        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting a list of chars") {
        char arr[] = {'y', 'm', 'a', 'c', 's', 'h', 'b'};
        char expected[] = {'a', 'b', 'c', 'h', 'm', 's', 'y'};
        constexpr int size = sizeof(arr) / sizeof(char);

        TimSort::sort(arr, size, 4);

        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Sorting a list of strings") {
        std::string arr[] = {"qSiVYcEivp", "KHvpckFnVd", "RLbAwtkquH", "YmWxBwcHOZ", "NNAXXpPkpR", "hfRcldttwR", "lWtzsZCyPh"};
        std::string expected[] = {"KHvpckFnVd", "NNAXXpPkpR", "RLbAwtkquH", "YmWxBwcHOZ", "hfRcldttwR", "lWtzsZCyPh", "qSiVYcEivp"};
        constexpr int size = sizeof(arr) / sizeof(std::string);

        TimSort::sort(arr, size, 4);

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

        TimSort::sort(arr, size, 4);

        for (int i = 0; i < size; i++) {
            CHECK_EQ(expected[i], arr[i]);
        }
    }

    SUBCASE("Testing the run length function") {
        int threshold = 8;

        CHECK_EQ(5, TimSort::calculate_run_length(19, threshold));
        CHECK_EQ(9, TimSort::calculate_run_length(17, threshold));
        CHECK_EQ(6, TimSort::calculate_run_length(21, threshold));
        CHECK_EQ(7, TimSort::calculate_run_length(7, threshold));
    }

    SUBCASE("Testing the partial insertion sort") {
        int arr[] = {4, -2, 7, 19, 3, 12, 9, 21, -5, 17, 8};

        TimSort::insertion_sort(arr, 0, 3);
        TimSort::insertion_sort(arr, 6, 8);
        TimSort::insertion_sort(arr, 9, 10);

        CHECK_EQ(-2, arr[0]);
        CHECK_EQ(4, arr[1]);
        CHECK_EQ(7, arr[2]);
        CHECK_EQ(19, arr[3]);
        CHECK_EQ(3, arr[4]);
        CHECK_EQ(12, arr[5]);
        CHECK_EQ(-5, arr[6]);
        CHECK_EQ(9, arr[7]);
        CHECK_EQ(21, arr[8]);
        CHECK_EQ(8, arr[9]);
        CHECK_EQ(17, arr[10]);
    }
}