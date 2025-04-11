//
// Created by aldin on 11/02/2025.
//

#pragma once
#include <cstdlib>

template<typename Data>
void QuickSort::quick_sort(Data *arr, int len) {
    shuffle(arr, len);
    sort(arr, 0, len - 1);
}

template<typename Data>
void QuickSort::shuffle(Data *arr, int len) {
    for (int i = 0; i < len; i++) {
        int r = i + rand() % (len - i);
        swap(arr, i, r);
    }
}

template<typename Data>
void QuickSort::sort(Data *arr, int low, int high) {
    if (high <= low) {
        return;
    }

    int j = partition(arr, low, high);
    sort(arr, low, j - 1);
    sort(arr, j + 1, high);
}

template<typename Data>
int QuickSort::partition(Data *arr, int low, int high) {
    int i = low;
    int j = high + 1;

    while (true) {
        while (arr[++i] < arr[low]) {
            if (i == high) {
                break;
            }
        }
        while (arr[low] < arr[--j]) {
            if (j == low) {
                break;
            }
        }
        if (i >= j) {
            break;
        }
        swap(arr, i, j);
    }
    swap(arr, low, j);
    return j;
}

template<typename Data>
void QuickSort::swap(Data *arr, int i, int j) {
    Data temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}




