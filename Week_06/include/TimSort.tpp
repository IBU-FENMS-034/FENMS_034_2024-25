//
// Created by aldin on 06/04/2025.
//

#pragma once
#include <algorithm>

template<typename Data>
void TimSort::sort(Data *arr, const int len, const int threshold) {
    int run = calculate_run_length(len, threshold);

    for (int low = 0; low < len; low += run) {
        int high = std::min(low + run - 1, len - 1);
        insertion_sort(arr, low, high);
    }

    Data* aux = new Data[len];
    for (int size = run; size < len; size *= 2) {
        for (int low = 0; low < len - size; low += 2 * size) {
            int mid = low + size - 1;
            int high = std::min(low + 2 * size - 1, len - 1);
            merge(arr, aux, low, mid, high);
        }
    }
    delete[] aux;
}

template<typename Data>
void TimSort::insertion_sort(Data *arr, const int low, const int high) {
    for (int i = low + 1; i <= high; i++) {
        for (int j = i; j > low; j--) {
            if (arr[j] < arr[j - 1]) {
                Data temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            } else {
                break;
            }
        }
    }
}

template<typename Data>
void TimSort::merge(Data *arr, Data *aux, const int low, const int mid, const int high) {
    for (int k = low; k <= high; k++) {
        aux[k] = arr[k];
    }

    int i = low;
    int j = mid + 1;
    for (int k = low; k <= high; k++) {
        if (i > mid) {
            arr[k] = aux[j++];
        } else if (j > high) {
            arr[k] = aux[i++];
        } else if (aux[j] < aux[i]) {
            arr[k] = aux[j++];
        } else {
            arr[k] = aux[i++];
        }
    }
}

inline int TimSort::calculate_run_length(const int initial_length, const int threshold) {
    int length = initial_length;
    int remainder = 0;

    while (length >= threshold) {
        remainder |= length % 2;
        length /= 2;
    }

    return length + remainder;
}



