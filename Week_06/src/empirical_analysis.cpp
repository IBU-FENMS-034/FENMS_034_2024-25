//
// Created by aldin on 05/02/2025.
//

#include <cstdlib>
#include <chrono>
#include <iostream>

#include "../../Week_05/include/ElementarySort.h"
#include "../../Week_06/include/MergeSort.h"

#define ARRAY_SIZE 100000

int* generate_array(int len);
void empirical_analysis(const char * algorithm);

int main() {
    empirical_analysis("shell_sort");
    empirical_analysis("merge_sort_recursive");
    empirical_analysis("merge_sort_bottom_up");
}

int* generate_array(const int len) {
    int* arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % (len * 10);
    }
    return arr;
}

void empirical_analysis(const char* algorithm) {
    int* arr = generate_array(ARRAY_SIZE);

    const auto start = std::chrono::high_resolution_clock::now();

    if (algorithm == "shell_sort") {
        ElementarySort::shell_sort(arr, ARRAY_SIZE);
    } else if (algorithm == "merge_sort_recursive") {
        MergeSort::merge_sort(arr, ARRAY_SIZE);
    } else if (algorithm == "merge_sort_bottom_up") {
        MergeSort::bottom_up_merge_sort(arr, ARRAY_SIZE);
    } else {
        std::cout << "Algorithm not recognized" << std::endl;
    }

    const auto stop = std::chrono::high_resolution_clock::now();

    const auto nanoDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    const auto microDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    const auto milliDuration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    const auto secDuration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    std::cout << "Algorithm: " << algorithm << std::endl;
    std::cout << "Elapsed time: "
        << nanoDuration.count() << " ns \t "
        << microDuration.count() << " μs \t "
        << milliDuration.count() << " ms \t "
        << secDuration.count() << " s"
        << std::endl;
    std::cout << std::endl;

    delete[] arr;
}