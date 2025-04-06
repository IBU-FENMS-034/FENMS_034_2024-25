//
// Created by aldin on 10/02/2025.
//

#ifndef MERGESORT_H
#define MERGESORT_H

namespace MergeSort {
    template<typename Data>
    void merge_sort(Data* arr, int len);

    template<typename Data>
    static void merge_sort(Data* arr, Data* aux, int low, int high);

    template<typename Data>
    void bottom_up_merge_sort(Data* arr, int len);

    template<typename Data>
    static void merge(Data* arr, Data* aux, int low, int mid, int high);
}

#include "MergeSort.tpp"

#endif //MERGESORT_H
