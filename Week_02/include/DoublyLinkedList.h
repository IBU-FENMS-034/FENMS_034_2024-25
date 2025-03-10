//
// Created by aldin on 10/03/2025.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "DoubleNode.h"
#include <initializer_list>

template <typename Data>
class DoublyLinkedList {
private:
    DoubleNode<Data>* head{};
    DoubleNode<Data>* tail{};
    int size{0};
public:
    // constructors
    DoublyLinkedList() = default;
    DoublyLinkedList(std::initializer_list<Data> list);
    // copy semantics
    DoublyLinkedList(const DoublyLinkedList<Data>& src);
    DoublyLinkedList<Data>& operator=(const DoublyLinkedList<Data>& src);
    // move semantics
    DoublyLinkedList(DoublyLinkedList<Data>&& src) noexcept;
    DoublyLinkedList<Data>& operator=(DoublyLinkedList<Data>&& src) noexcept;
    // destructor
    ~DoublyLinkedList();

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

    // used for tests, DO NOT REMOVE
    DoubleNode<Data>* get_front() const; // return "head" node
    DoubleNode<Data>* get_back() const; // return "tail" node
};

#include "DoublyLinkedList.tpp"

#endif //DOUBLYLINKEDLIST_H
