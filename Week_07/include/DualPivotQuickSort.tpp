//
// Created by aldin on 11/02/2025.
//

#pragma once
#include <cstdlib>

template<typename Data>
void DualPivotQuickSort::quick_sort(Data *arr, int len) {
    shuffle(arr, len);
    sort(arr, 0, len - 1);
}

template<typename Data>
void DualPivotQuickSort::sort(Data *arr, int low, int high) {
    if (high <= low) {
        return;
    }

    int* pivots = partition(arr, low, high);
    int lt = pivots[0];
    int gt = pivots[1];
    delete[] pivots;

    sort(arr, low, lt - 1);
    sort(arr, lt + 1, gt - 1);
    sort(arr, gt + 1, high);
}

template<typename Data>
int* DualPivotQuickSort::partition(Data *arr, int low, int high) {
    if (arr[high] < arr[low]) {
        swap(arr, low, high);
    }

    int lt = low + 1;
    int gt = high - 1;
    int k = lt;
    while (k <= gt) {
        if (arr[k] < arr[low]) {
            swap(arr, k++, lt++);
        } else if (arr[high] < arr[k]) {
            swap(arr, k, gt--);
        } else {
            k++;
        }
    }
    swap(arr, low, --lt);
    swap(arr, high, ++gt);

    int* pivots = new int[2];
    pivots[0] = lt;
    pivots[1] = gt;
    return pivots;
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




