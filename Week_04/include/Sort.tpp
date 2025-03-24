#pragma once

template<typename Data>
void Sort::bubble_sort(Data *arr, const int len) {
    for (int i = 0; i < len; i++) {
        bool swapped = false;

        for (int j = 1; j < len - i; j++) {
            if (arr[j] < arr[j - 1]) {
                swap(arr, j, j - 1);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

template<typename Data>
void Sort::swap(Data* arr, int a, int b) {
    Data temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}