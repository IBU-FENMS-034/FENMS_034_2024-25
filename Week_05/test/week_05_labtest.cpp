//
// Created by aldin on 14/02/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/BinaryInsertionSort.h"
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

TEST_CASE("Binary insertion sort") {
    SUBCASE("Sorting a list of integers") {
        LinkedList<int> list = {5, -1, 7, 19, 3, 12, 4};
        int expected[] = {-1, 3, 4, 5, 7, 12, 19};

        BinaryInsertionSort::sort(list);

        Node<int>* current = list.get_head();
        int i = 0;
        while (current != nullptr) {
            CHECK_EQ(expected[i++], current->data);
            current = current->next;
        }
    }

    SUBCASE("Sorting a list of doubles") {
        LinkedList<double> list = {3.14, -11.2, 43.6, 22.5, 7.12, 5.24, 66.2};
        double expected[] = {-11.2, 3.14, 5.24, 7.12, 22.5, 43.6, 66.2};

        BinaryInsertionSort::sort(list);

        Node<double>* current = list.get_head();
        int i = 0;
        while (current != nullptr) {
            CHECK_EQ(expected[i++], current->data);
            current = current->next;
        }
    }

    SUBCASE("Sorting a list of chars") {
        LinkedList<char> list = {'y', 'm', 'a', 'c', 's', 'h', 'b'};
        char expected[] = {'a', 'b', 'c', 'h', 'm', 's', 'y'};

        BinaryInsertionSort::sort(list);

        Node<char>* current = list.get_head();
        int i = 0;
        while (current != nullptr) {
            CHECK_EQ(expected[i++], current->data);
            current = current->next;
        }
    }

    SUBCASE("Sorting a list of strings") {
        LinkedList<std::string> list = {"qSiVYcEivp", "KHvpckFnVd", "RLbAwtkquH", "YmWxBwcHOZ", "NNAXXpPkpR", "hfRcldttwR", "lWtzsZCyPh"};
        std::string expected[] = {"KHvpckFnVd", "NNAXXpPkpR", "RLbAwtkquH", "YmWxBwcHOZ", "hfRcldttwR", "lWtzsZCyPh", "qSiVYcEivp"};

        BinaryInsertionSort::sort(list);

        Node<std::string>* current = list.get_head();
        int i = 0;
        while (current != nullptr) {
            CHECK_EQ(expected[i++], current->data);
            current = current->next;
        }
    }

    SUBCASE("Sorting a list of objects") {
        LinkedList<Student> list = {
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

        BinaryInsertionSort::sort(list);

        Node<Student>* current = list.get_head();
        int i = 0;
        while (current != nullptr) {
            CHECK_EQ(expected[i++], current->data);
            current = current->next;
        }
    }

    SUBCASE("Testing the insertion point function") {
        LinkedList<int> list = {-2, 3, 7, 12, 6, 19, 4};

        CHECK_EQ(0, BinaryInsertionSort::find_insertion_point(list, 3, -5));
        CHECK_EQ(1, BinaryInsertionSort::find_insertion_point(list, 3, 2));
        CHECK_EQ(2, BinaryInsertionSort::find_insertion_point(list, 3, 5));
        CHECK_EQ(3, BinaryInsertionSort::find_insertion_point(list, 3, 9));
        CHECK_EQ(4, BinaryInsertionSort::find_insertion_point(list, 3, 15));
    }
}