//
// Created by aldin on 10/03/2025.
//

#ifndef LINKEDLIST_TPP
#define LINKEDLIST_TPP
#include <stdexcept>
#include <iterator>

template<typename Data>
void LinkedList<Data>::add_to_front(const Data& data) {
    Node<Data>* new_node = new Node<Data>();
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    ++size;
}

template<typename Data>
void LinkedList<Data>::remove_from_front() {
    if (head == nullptr) {
        throw std::out_of_range("List is empty");
    }
    const Node<Data>* temp = head;
    head = head->next;
    delete temp;
    --size;
}

template<typename Data>
void LinkedList<Data>::add_to_back(const Data& data) {
    Node<Data>* new_node = new Node<Data>();
    new_node->data = data;

    if (head == nullptr) {
        head = new_node;
    } else {
        Node<Data>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    ++size;
}

template<typename Data>
void LinkedList<Data>::remove_from_back() {
    if (head == nullptr) {
        throw std::out_of_range("List is empty");
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node<Data>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    --size;
}

template<typename Data>
Data& LinkedList<Data>::get(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index is out of range");
    }

    Node<Data>* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp->data;
}

template<typename Data>
int LinkedList<Data>::count() const {
    return size;
}

template<typename Data>
void LinkedList<Data>::reverse() {
    Node<Data>* current = head;
    Node<Data>* prev = nullptr;

    while (current != nullptr) {
        Node<Data>* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template<typename Data>
class LinkedList<Data>::Iterator : public std::iterator<std::forward_iterator_tag, Data> {
private:
    Node<Data>* current;
public:
    explicit Iterator(Node<Data>* current) : current(current) {}
    Data& operator*() {
        return current->data;
    }
    Iterator& operator++() {
        current = current->next;
        return *this;
    }

    Iterator operator++(int) {
        Iterator temp = *this;
        current = current->next;
        return temp;
    }

    bool operator==(const Iterator& other) const {
        return current == other.current;
    }

    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }
};

template<typename Data>
typename LinkedList<Data>::Iterator LinkedList<Data>::begin() {
    return Iterator(head);
}

template<typename Data>
typename LinkedList<Data>::Iterator LinkedList<Data>::end() {
    return Iterator(nullptr);
}

template<typename Data>
const Data& LinkedList<Data>::operator[](int index) const {
    return get(index);
}

template<typename Data>
Data& LinkedList<Data>::operator[](const int index) {
    return get(index);
}

template<typename Data>
LinkedList<Data>::~LinkedList() {
    while (head != nullptr) {
        const Node<Data>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename Data>
LinkedList<Data>::LinkedList(const LinkedList<Data> &src) {
    std::cout << "Linked list copy constructor" << std::endl;
    Node<Data>* current = src.head;
    while (current != nullptr) {
        add_to_back(current->data);
        current = current->next;
    }
}

template<typename Data>
LinkedList<Data> &LinkedList<Data>::operator=(const LinkedList<Data> &src) {
    std::cout << "Linked list copy assignment" << std::endl;
    // Prevent self-assignment
    if (this != &src) {
        // Clean up old data
        while (head != nullptr) {
            remove_from_front();
        }

        // Add new data
        Node<Data>* current = src.head;
        while (current != nullptr) {
            add_to_back(current->data);
            current = current->next;
        }
    }
    return *this;

    // Alternative way:
    // if (this != &src) {
    //     LinkedList<Data> temp(src);
    //     std::swap(head, temp.head);
    //     std::swap(size, temp.size);
    // }
    // return *this;
}

template<typename Data>
LinkedList<Data>::LinkedList(LinkedList<Data> &&src) noexcept {
    std::cout << "Linked list move constructor" << std::endl;
    head = src.head;
    size = src.size;

    src.head = nullptr;
    src.size = 0;

    // Alternative way:
    // std::swap(head, src.head);
    // std::swap(size, src.size);
}

template<typename Data>
LinkedList<Data> &LinkedList<Data>::operator=(LinkedList<Data> &&src) noexcept {
    std::cout << "Linked list move assignment" << std::endl;
    // Prevent self-assignment
    if (this != &src) {
        // Clean up old resources
        while (head != nullptr) {
            remove_from_front();
        }

        // Change ownership
        head = src.head;
        size = src.size;

        src.head = nullptr;
        src.size = 0;
    }
    return *this;

    // Alternative way:
    // if (this != &src) {
    //     std::swap(head, src.head);
    //     std::swap(size, src.size);
    // }
    // return *this;
}

template<typename Data>
LinkedList<Data>::LinkedList(std::initializer_list<Data> list) {
    std::cout << "Linked list initializer" << std::endl;
    for (auto it = list.begin(); it != list.end(); ++it) {
        add_to_back(*it);
    }
}

#endif //LINKEDLIST_TPP
