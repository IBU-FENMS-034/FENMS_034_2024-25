#pragma once

template<typename Data>
void ElementarySort::selection_sort(Data *arr, const int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr, min, i);
    }
}

template<typename Data>
void ElementarySort::insertion_sort(Data *arr, const int len) {
    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr, j, j - 1);
            } else {
                break;
            }
        }
    }
}

template<typename Data>
void ElementarySort::shell_sort(Data *arr, const int len) {
    int h = 1;
    while (h < len / 3) {
        h = 3 * h + 1;
    }

    while (h >= 1) {
        for (int i = h; i < len; i++) {
            for (int j = i; j >= h; j -= h) {
                if (arr[j] < arr[j - h]) {
                    swap(arr, j, j - h);
                } else {
                    break;
                }
            }
        }
        h = h / 3;
    }
}

template<typename Data>
void ElementarySort::swap(Data* arr, int a, int b) {
    Data temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}