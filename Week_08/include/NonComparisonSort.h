//
// Created by aldin on 11/02/2025.
//

#ifndef NONCOMPARISONSORT_H
#define NONCOMPARISONSORT_H

namespace NonComparisonSort {
    template<typename Data>
    void radix_sort(Data* arr, int len);

    template<typename Data>
    static void sort(Data* arr, int len, int exp);

    template<typename Data>
    static int get_max(Data* arr, int len);

    template<typename Data>
    void counting_sort(Data* arr, int len);
}

#include "NonComparisonSort.tpp"

#endif //NONCOMPARISONSORT_H
