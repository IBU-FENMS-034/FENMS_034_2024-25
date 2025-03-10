//
// Created by aldin on 10/03/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <initializer_list>

template <typename Data>
class LinkedList {
private:
    Node<Data>* head{};
    int size{0};
public:
    // constructors
    LinkedList() = default;
    LinkedList(std::initializer_list<Data> list);
    // copy semantics
    LinkedList(const LinkedList<Data>& src);
    LinkedList<Data>& operator=(const LinkedList<Data>& src);
    // move semantics
    LinkedList(LinkedList<Data>&& src) noexcept;
    LinkedList<Data>& operator=(LinkedList<Data>&& src) noexcept;
    // destructor
    ~LinkedList();

    void add_to_front(const Data& data);
    void add_to_back(const Data& data);
    void remove_from_front();
    void remove_from_back();
    Data& get(int index);
    int count() const;
    void reverse();
    // iterator
    class Iterator;
    Iterator begin();
    Iterator end();
    // overloading []
    const Data& operator[](int index) const;
    Data& operator[](int index);
};

#include "LinkedList.tpp"

#endif //LINKEDLIST_H
