//
// Created by aldin on 16/03/2025.
//

#ifndef QUEUE_TPP
#define QUEUE_TPP

template<typename Data>
void Queue<Data>::enqueue(const Data& data) {
    Node<Data> *new_node = new Node<Data>();
    new_node->data = data;

    if (is_empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    ++length;
}

template<typename Data>
Data Queue<Data>::dequeue() {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }

    Node<Data> *temp = head;
    Data data = temp->data;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    --length;
    delete temp;
    return data;
}

template<typename Data>
const Data &Queue<Data>::peek() const {
    if (is_empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return head->data;
}

template<typename Data>
bool Queue<Data>::is_empty() const {
    return head == nullptr;
}

template<typename Data>
int Queue<Data>::size() const {
    return length;
}

template<typename Data>
void Queue<Data>::reverse() {
    Node<Data>* current = head;
    Node<Data>* prev = nullptr;

    tail = head;
    while (current != nullptr) {
        Node<Data>* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template<typename Data>
Queue<Data>::~Queue() {
    while (head != nullptr) {
        const Node<Data> *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

template<typename Data>
Queue<Data>::Queue(std::initializer_list<Data> queue) {
    for (auto it = queue.begin(); it != queue.end(); ++it) {
        enqueue(*it);
    }
}

template<typename Data>
Queue<Data>::Queue(const Queue &src) {
    Node<Data> *current = src.head;

    while (current != nullptr) {
        enqueue(current->data);
        current = current->next;
    }
}

template<typename Data>
Queue<Data> &Queue<Data>::operator=(const Queue &src) {
    if (this != &src) {
        while (head != nullptr) {
            dequeue();
        }

        Node<Data> *current = src.head;

        while (current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }
    }
    return *this;
}

template<typename Data>
Queue<Data>::Queue(Queue &&src) noexcept {
    head = src.head;
    tail = src.tail;
    length = src.length;

    src.head = nullptr;
    src.tail = nullptr;
    src.length = 0;
}

template<typename Data>
Queue<Data> &Queue<Data>::operator=(Queue &&src) noexcept {
    if (this != &src) {
        while (head != nullptr) {
            dequeue();
        }

        head = src.head;
        tail = src.tail;
        length = src.length;

        src.head = nullptr;
        src.tail = nullptr;
        src.length = 0;
    }
    return *this;
}

#endif //QUEUE_TPP
