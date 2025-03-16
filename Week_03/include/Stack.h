//
// Created by aldin on 16/03/2025.
//

#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <stdexcept>

template <typename Data>
class Stack {
private:
    Node<Data>* top{};
    int length{0};
public:
    // constructors
    Stack() = default;
    Stack(std::initializer_list<Data> stack);
    // copy semantics
    Stack(const Stack& src);
    Stack& operator=(const Stack& src);
    // move semantics
    Stack(Stack&& src) noexcept;
    Stack& operator=(Stack&& src) noexcept;
    // destructor
    ~Stack();

    void push(const Data& data);
    Data pop();
    bool is_empty() const;
    int size() const;
    const Data& peek() const;
    void reverse();
};

#include "Stack.tpp"

#endif //STACK_H
