//
// Created by aldin on 27/12/2024.
//

#ifndef SORT_H
#define SORT_H

namespace Sort {
    template<typename Data>
    static void swap(Data* arr, int a, int b);
    template<typename Data>
    void bubble_sort(Data* arr, int len);

};

#include "Sort.tpp"

#endif //SORT_H
