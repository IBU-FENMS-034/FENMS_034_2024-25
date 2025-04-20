//
// Created by aldin on 11/02/2025.
//

#include <iostream>
#include "../include/NonComparisonSort.h"

void radix_sort_demo();
void counting_sort_demo();

int main() {
    radix_sort_demo();
    std::cout << std::endl;
    counting_sort_demo();
}

void radix_sort_demo() {
    int elements[] = {5, 1, 23, 8, 17, 4, 2, 6};
    constexpr int size = sizeof(elements) / sizeof(int); // OR std::size(elements)

    std::cout << "Radix sort: " << std::endl;
    NonComparisonSort::radix_sort(elements, size);
    for (const int i: elements) {
        std::cout << i << std::endl;
    }
}

void counting_sort_demo() {
    int elements[] = {5, 1, 23, 8, 17, 4, 2, 6};
    constexpr int size = sizeof(elements) / sizeof(int); // OR std::size(elements)

    std::cout << "Counting sort: " << std::endl;
    NonComparisonSort::counting_sort(elements, size);
    for (const int i: elements) {
        std::cout << i << std::endl;
    }
}