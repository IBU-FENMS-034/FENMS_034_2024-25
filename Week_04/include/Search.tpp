#pragma once

template<typename Data>
int Search::linear_search(const Data* elements, const int len, const Data& key) {
    for (int i = 0; i < len; i++) {
        if (elements[i] == key) {
            return i;
        }
    }
    return -1;
}

template<typename Data>
int Search::binary_search(const Data *elements, const int len, const Data &key) {
    int low = 0;
    int high = len - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (key == elements[mid]) {
            return mid;
        } else if (key < elements[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}