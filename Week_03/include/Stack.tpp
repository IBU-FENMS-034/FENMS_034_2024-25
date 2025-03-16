//
// Created by aldin on 16/03/2025.
//

#ifndef STACK_TPP
#define STACK_TPP

template<typename Data>
void Stack<Data>::push(const Data& data) {
    Node<Data> *new_node = new Node<Data>();
    new_node->data = data;
    new_node->next = top;
    top = new_node;
    ++length;
}

template<typename Data>
Data Stack<Data>::pop() {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }

    Node<Data> *temp = top;
    Data data = temp->data;
    top = top->next;

    --length;
    delete temp;
    return data;
}

template<typename Data>
const Data& Stack<Data>::peek() const {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return top->data;
}

template<typename Data>
bool Stack<Data>::is_empty() const {
    return top == nullptr;
}

template<typename Data>
int Stack<Data>::size() const {
    return length;
}

template<typename Data>
void Stack<Data>::reverse() {
    Node<Data>* current = top;
    Node<Data>* prev = nullptr;

    while (current != nullptr) {
        Node<Data>* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    top = prev;
}

template<typename Data>
Stack<Data>::~Stack() {
    while (top != nullptr) {
        const Node<Data> *temp = top;
        top = top->next;
        delete temp;
    }
}

template<typename Data>
Stack<Data>::Stack(std::initializer_list<Data> stack) {
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        push(*it);
    }
}

template<typename Data>
Stack<Data>::Stack(const Stack &src) {
    Node<Data> *current = src.top;

    while (current != nullptr) {
        push(current->data);
        current = current->next;
    }
    reverse();
}

template<typename Data>
Stack<Data> &Stack<Data>::operator=(const Stack &src) {
    if (this != &src) {
        while (top != nullptr) {
            pop();
        }

        Node<Data>* current = src.top;
        while (current != nullptr) {
            push(current->data);
            current = current->next;
        }
        reverse();
    }
    return *this;
}

template<typename Data>
Stack<Data>::Stack(Stack &&src) noexcept {
    top = src.top;
    length = src.length;

    src.top = nullptr;
    src.length = 0;
}

template<typename Data>
Stack<Data> &Stack<Data>::operator=(Stack &&src) noexcept {
    if (this != &src) {
        while (top != nullptr) {
            pop();
        }

        top = src.top;
        length = src.length;

        src.top = nullptr;
        src.length = 0;
    }
    return *this;
}

#endif //STACK_TPP
