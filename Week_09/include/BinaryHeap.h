//
// Created by aldin on 12/02/2025.
//

#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <initializer_list>

template <typename Data>
class BinaryHeap {
private:
    Data* pq{};
    int length{0};
    int pq_size{2};
    bool is_max_heap{true};
    void swim(int k);
    void sink(int k);
    void resize(int capacity);
    bool less(int a, int b);
    void swap(int a, int b);
public:
    explicit BinaryHeap(bool is_max = true);
    BinaryHeap(std::initializer_list<Data> list, bool is_max = true);
    BinaryHeap(const BinaryHeap& src);
    BinaryHeap& operator=(const BinaryHeap& src);
    BinaryHeap(BinaryHeap&& src) noexcept;
    BinaryHeap& operator=(BinaryHeap&& src) noexcept;
    ~BinaryHeap();
    void insert(const Data& data);
    Data poll();
    Data peek();
    bool is_empty() const;
    int size() const;
    static void heap_sort(Data* data, int len);
};

#include "BinaryHeap.tpp"

#endif //BINARYHEAP_H
