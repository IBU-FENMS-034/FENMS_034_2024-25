//
// Created by aldin on 11/02/2025.
//

#pragma once

template<typename Data>
void NonComparisonSort::radix_sort(Data *arr, int len) {
    int max = get_max(arr, len);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        sort(arr, len, exp);
    }
}

template<typename Data>
void NonComparisonSort::sort(Data *arr, int len, int exp) {
    Data* aux = new Data[len];
    int frequency[10] = {0};

    for (int i = 0; i < len; i++) {
        int digit = (arr[i] / exp) % 10;
        ++frequency[digit];
    }

    for (int i = 1; i < 10; i++) {
        frequency[i] += frequency[i - 1];
    }

    for (int i = len - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        aux[--frequency[digit]] = arr[i];
    }

    for (int i = 0; i < len; i++) {
        arr[i] = aux[i];
    }

    delete[] aux;
}

template<typename Data>
void NonComparisonSort::counting_sort(Data *arr, int len) {
    int max = get_max(arr, len);
    Data* count = new Data[max + 1]();
    Data* output = new Data[len];

    for (int i = 0; i < len; i++) {
        ++count[arr[i]];
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = len - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < len; i++) {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}


template<typename Data>
int NonComparisonSort::get_max(Data *arr, int len) {
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
