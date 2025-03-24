//
// Created by aldin on 27/12/2024.
//

#ifndef SEARCH_H
#define SEARCH_H

namespace Search {
    template<typename Data>
    int linear_search(const Data* elements, int len, const Data& key);
    template<typename Data>
    int binary_search(const Data* elements, int len, const Data& key);

};

#include "Search.tpp"

#endif //SEARCH_H
