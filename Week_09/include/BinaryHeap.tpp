//
// Created by aldin on 12/02/2025.
//

#pragma once

template<typename Data>
BinaryHeap<Data>::BinaryHeap(bool is_max) {
    pq = new Data[pq_size]{};
    is_max_heap = is_max;
}

template<typename Data>
BinaryHeap<Data>::BinaryHeap(std::initializer_list<Data> list, bool is_max) {
    pq = new Data[pq_size]{};
    is_max_heap = is_max;
    for (auto it = list.begin(); it != list.end(); it++) {
        insert(*it);
    }
}

template<typename Data>
BinaryHeap<Data>::BinaryHeap(const BinaryHeap &src) {
    length = src.length;
    pq_size = src.pq_size;
    pq = new Data[pq_size]{};

    for (int i = 1; i <= length; i++) {
        pq[i] = src.pq[i];
    }
}

template<typename Data>
BinaryHeap<Data> &BinaryHeap<Data>::operator=(const BinaryHeap &src) {
    if (this != &src) {
        delete[] pq;

        length = src.length;
        pq_size = src.pq_size;
        pq = new Data[pq_size]{};
        for (int i = 1; i <= length; i++) {
            pq[i] = src.pq[i];
        }
    }
    return *this;
}

template<typename Data>
BinaryHeap<Data>::BinaryHeap(BinaryHeap &&src) noexcept {
    pq = src.pq;
    length = src.length;
    pq_size = src.pq_size;

    src.pq = nullptr;
    src.length = 0;
    src.pq_size = 2;
}

template<typename Data>
BinaryHeap<Data> &BinaryHeap<Data>::operator=(BinaryHeap &&src) noexcept {
    if (this != &src) {
        delete[] pq;

        pq = src.pq;
        length = src.length;
        pq_size = src.pq_size;

        src.pq = nullptr;
        src.length = 0;
        src.pq_size = 2;
    }
    return *this;
}

template<typename Data>
BinaryHeap<Data>::~BinaryHeap() {
    delete[] pq;
}

template<typename Data>
void BinaryHeap<Data>::insert(const Data &data) {
    if (pq_size == length + 1) {
        resize(2 * pq_size);
    }
    pq[++length] = data;
    swim(length);
}

template<typename Data>
void BinaryHeap<Data>::swim(int k) {
    while (k > 1 && less(k / 2, k)) {
        swap(k, k / 2);
        k = k / 2;
    }
}

template<typename Data>
Data BinaryHeap<Data>::poll() {
    Data max = pq[1];
    swap(1, length--);
    // delete pq[length + 1];

    if (length > 0 && length == pq_size / 4) {
        resize(pq_size / 2);
    }

    sink(1);
    return max;
}

template<typename Data>
void BinaryHeap<Data>::sink(int k) {
    while (2 * k <= length) {
        int j = 2 * k;
        if (j < length && less(j, j + 1)) {
            ++j;
        }

        if (!less(k, j)) {
            break;
        }

        swap(k, j);
        k = j;
    }
}

template<typename Data>
Data BinaryHeap<Data>::peek() {
    return pq[1];
}

template<typename Data>
bool BinaryHeap<Data>::is_empty() const {
    return length == 0;
}

template<typename Data>
int BinaryHeap<Data>::size() const {
    return length;
}

template<typename Data>
void BinaryHeap<Data>::heap_sort(Data *data, int len) {
    // your code
}

template<typename Data>
void BinaryHeap<Data>::resize(int capacity) {
    Data* copy = new Data[capacity]{};
    const Data* old_pq = pq;
    for (int i = 1; i <= length; i++) {
        copy[i] = pq[i];
    }
    pq = copy;
    pq_size = capacity;
    delete[] old_pq;
}

template<typename Data>
bool BinaryHeap<Data>::less(int a, int b) {
    return is_max_heap ? pq[a] < pq[b] : pq[a] > pq[b];
}

template<typename Data>
void BinaryHeap<Data>::swap(int a, int b) {
    Data temp = pq[a];
    pq[a] = pq[b];
    pq[b] = temp;
}



