//
// Created by aldin on 10/02/2025.
//


#include <iostream>
#include "../include/MergeSort.h"

void recursive_merge_sort_demo();
void bottom_up_merge_sort_demo();

int main() {
    recursive_merge_sort_demo();
    std::cout << std::endl;
    bottom_up_merge_sort_demo();
}

void recursive_merge_sort_demo() {
    int elements[] = {5, -1, 23, 8, 17, 4, 2, 6};
    constexpr int size = sizeof(elements) / sizeof(int); // OR std::size(elements)

    std::cout << "Merge sort (recursive): " << std::endl;
    MergeSort::merge_sort(elements, size);
    for (const int i: elements) {
        std::cout << i << std::endl;
    }
}

void bottom_up_merge_sort_demo() {
    int elements[] = {5, -1, 23, 8, 17, 4, 2, 6};
    constexpr int size = sizeof(elements) / sizeof(int); // OR std::size(elements)

    std::cout << "Merge sort (bottom-up): " << std::endl;
    MergeSort::bottom_up_merge_sort(elements, size);
    for (const int i: elements) {
        std::cout << i << std::endl;
    }
}