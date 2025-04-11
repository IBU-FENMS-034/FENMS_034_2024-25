//
// Created by aldin on 11/02/2025.
//

#pragma once
#include <cstdlib>

template<typename Data>
void DualPivotQuickSort::quick_sort(Data *arr, int len) {
    // your code
}

template<typename Data>
void DualPivotQuickSort::sort(Data *arr, int low, int high) {
    // your code
}

template<typename Data>
int* DualPivotQuickSort::partition(Data *arr, int low, int high) {
    // your code
}

template<typename Data>
void DualPivotQuickSort::shuffle(Data *arr, int len) {
    for (int i = 0; i < len; i++) {
        int r = i + rand() % (len - i);
        swap(arr, i, r);
    }
}

template<typename Data>
void DualPivotQuickSort::swap(Data *arr, int i, int j) {
    Data temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}




