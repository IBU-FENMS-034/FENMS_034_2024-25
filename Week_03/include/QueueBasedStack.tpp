#ifndef QUEUEBASEDSTACK_TPP
#define QUEUEBASEDSTACK_TPP

#include "QueueBasedStack.h"
#include <stdexcept>
#include <utility>

template<typename Data>
QueueBasedStack<Data>::QueueBasedStack() = default;

template<typename Data>
void QueueBasedStack<Data>::push(const Data& data) {
    q2.enqueue(data);

    while (!q1.is_empty()) {
        q2.enqueue(q1.dequeue());
    }
    std::swap(q1, q2);
}

template<typename Data>
Data QueueBasedStack<Data>::pop() {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return q1.dequeue();
}

template<typename Data>
Data QueueBasedStack<Data>::peek() const {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return q1.peek();
}

template<typename Data>
int QueueBasedStack<Data>::size() const {
    return q1.size();
}

template<typename Data>
bool QueueBasedStack<Data>::is_empty() const {
    return q1.is_empty();
}

#endif // QUEUEBASEDSTACK_TPP
