#include <array>
#include <iostream>
#include "../include/Search.h"
#include "../include/Sort.h"
#include "../include/Student.h"

void search_demo();
void sort_demo();

int main() {
    search_demo();
    sort_demo();
}

void search_demo() {
    int elements[] = {5, -1, 23, 8, 17, 4, 2, 6};
    int size = sizeof(elements) / sizeof(int); // OR std::size(elements)
    std::cout << "size o: " << size << std::endl;
    std::cout << "Linear search: " << Search::linear_search(elements, size, 17) << std::endl;
    std::cout << "Linear search: " << Search::linear_search(elements, size, 34) << std::endl;
    std::cout << std::endl;

    int elements2[] = {-5, -1, 8, 23, 37, 42, 202, 634};
    int size2 = sizeof(elements2) / sizeof(int); // OR std::size(elements2)

    std::cout << "Binary search: " << Search::binary_search(elements2, size2, 37)  << std::endl;
    std::cout << "Binary search: " << Search::binary_search(elements2, size2, 120)  << std::endl;
    std::cout << std::endl;
}

void sort_demo() {
    int elements[] = {5, -1, 23, 8, 17, 4, 2, 6};
    int size = sizeof(elements) / sizeof(int);

    std::cout << "Bubble sort: " << std::endl;
    Sort::bubble_sort(elements, size);
    for (const int i: elements) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Sorting structs:" << std::endl;
    Student students[] = {
        Student("John", "Doe", 100),
        Student("Jane", "Doe", 80),
        Student("Charles", "Doe", 90),
    };

    Sort::bubble_sort(students, 3);
    for (const Student s: students) {
        std::cout << s.name << "," << s.department << "," << s.gpa << std::endl;
    }
}