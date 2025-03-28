//
// Created by aldin on 05/02/2025.
//
#include <iostream>
#include "../include/ElementarySort.h"

void selection_sort_demo();
void insertion_sort_demo();
void shell_sort_demo();

int main() {
    selection_sort_demo();
    std::cout << std::endl;

    insertion_sort_demo();
    std::cout << std::endl;

    shell_sort_demo();
}

void selection_sort_demo() {
    int elements[] = {5, -1, 23, 8, 17, 4, 2, 6};
    constexpr int size = sizeof(elements) / sizeof(int); // OR std::size(elements)

    std::cout << "Selection sort: " << std::endl;
    ElementarySort::selection_sort(elements, size);
    for (const int i: elements) {
        std::cout << i << std::endl;
    }
}

void insertion_sort_demo() {
    int elements[] = {5, -1, 23, 8, 17, 4, 2, 6};
    constexpr int size = sizeof(elements) / sizeof(int); // OR std::size(elements)

    std::cout << "Insertion sort: " << std::endl;
    ElementarySort::insertion_sort(elements, size);
    for (const int i: elements) {
        std::cout << i << std::endl;
    }
}

void shell_sort_demo() {
    int elements[] = {5, -1, 23, 8, 17, 4, 2, 6};
    constexpr int size = sizeof(elements) / sizeof(int); // OR std::size(elements)

    std::cout << "Shell sort: " << std::endl;
    ElementarySort::shell_sort(elements, size);
    for (const int i: elements) {
        std::cout << i << std::endl;
    }
}