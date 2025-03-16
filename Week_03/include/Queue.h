//
// Created by aldin on 16/03/2025.
//

#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_H
#include "Node.h"
#include <stdexcept>
#include <initializer_list>

template <typename Data>
class Queue {
private:
    Node<Data>* head{};
    Node<Data>* tail{};
    int length{0};
public:
    // constructors
    Queue() = default;
    Queue(std::initializer_list<Data> queue);
    // copy semantics
    Queue(const Queue& src);
    Queue& operator=(const Queue& src);
    // move semantics
    Queue(Queue&& src) noexcept;
    Queue& operator=(Queue&& src) noexcept;
    // destructor
    ~Queue();

    void enqueue(const Data& data);
    Data dequeue();
    bool is_empty() const;
    int size() const;
    const Data& peek() const;
    void reverse();
};

#include "Queue.tpp"

#endif //QUEUE_H
