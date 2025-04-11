//
// Created by aldin on 11/02/2025.
//

#ifndef DUALPIVOTQUICKSORT_H
#define DUALPIVOTQUICKSORT_H

namespace DualPivotQuickSort {
    template<typename Data>
    void quick_sort(Data* arr, int len);

    template<typename Data>
    static void shuffle(Data* arr, int len);

    template<typename Data>
    static void sort(Data* arr, int low, int high);

    template<typename Data>
    int* partition(Data* arr, int low, int high);

    template<typename Data>
    static void swap(Data* arr, int i, int j);
}

#include "DualPivotQuickSort.tpp"

#endif //DUALPIVOTQUICKSORT_H
