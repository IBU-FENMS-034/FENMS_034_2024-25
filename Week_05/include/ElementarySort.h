//
// Created by aldin on 05/02/2025.
//

#ifndef ELEMENTARY_SORT_H
#define ELEMENTARY_SORT_H

namespace ElementarySort {
    template<typename Data>
    static void swap(Data* arr, int a, int b);
    template<typename Data>
    void selection_sort(Data* arr, int len);
    template<typename Data>
    void insertion_sort(Data* arr, int len);
    template<typename Data>
    void shell_sort(Data* arr, int len);
}

#include "ElementarySort.tpp"

#endif //ELEMENTARY_SORT_H
