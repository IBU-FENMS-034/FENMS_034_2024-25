//
// Created by aldin on 11/02/2025.
//

#include <iostream>
#include "../include/QuickSort.h"

int main() {
    int elements[] = {5, -1, 23, 8, 17, 4, 2, 6};
    constexpr int size = sizeof(elements) / sizeof(int); // OR std::size(elements)

    std::cout << "Quick sort: " << std::endl;
    QuickSort::quick_sort(elements, size);
    for (const int i: elements) {
        std::cout << i << std::endl;
    }
}