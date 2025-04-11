//
// Created by aldin on 11/02/2025.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H

namespace QuickSort {
    template<typename Data>
    void quick_sort(Data* arr, int len);

    template<typename Data>
    static void shuffle(Data* arr, int len);

    template<typename Data>
    static void sort(Data* arr, int low, int high);

    template<typename Data>
    static int partition(Data* arr, int low, int high);

    template<typename Data>
    static void swap(Data* arr, int i, int j);
}

#include "QuickSort.tpp"

#endif //QUICKSORT_H
