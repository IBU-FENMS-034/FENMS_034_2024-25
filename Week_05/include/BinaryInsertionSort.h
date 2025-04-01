//
// Created by aldin on 01/04/2025.
//

#ifndef BINARYINSERTIONSORT_H
#define BINARYINSERTIONSORT_H
#include <initializer_list>
#include <stdexcept>

template <typename Data>
class LinkedList;

/**
 * Binary insertion sort
 */
namespace BinaryInsertionSort {
    template<typename Data>
    void sort(LinkedList<Data>& list);

    template<typename Data>
    int find_insertion_point(LinkedList<Data>& list, int high, Data key);

};

/**
 * Linked list to be used (do not modify)
 */
template<typename Data>
struct Node {
    Data data;
    Node *next{};

    Node() = default;
    explicit Node(Data data) : data(data) {}
};

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
    void add(int index, const Data& data);
    void remove(int index);
    Data& get(int index);

    int count() const;
    void reverse();
    Node<Data>* get_head() const;
    friend void BinaryInsertionSort::sort<>(LinkedList<Data>& list);
    friend int BinaryInsertionSort::find_insertion_point<>(LinkedList<Data>& list, int high, Data key);
};

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

template <typename Data>
void LinkedList<Data>::add(const int index, const Data& data) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index is out of range");
    }

    Node<Data>* new_node = new Node<Data>();
    new_node->data = data;

    if (index == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        Node<Data>* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    ++size;
}

template <typename Data>
void LinkedList<Data>::remove(const int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index is out of range");
    }

    if (head == nullptr) {
        throw std::out_of_range("List is empty");
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else if (index == 0) {
        Node<Data>* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node<Data>* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<Data>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    --size;
}

template<typename Data>
Data& LinkedList<Data>::get(const int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index is out of range");
    }

    Node<Data>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template<typename Data>
int LinkedList<Data>::count() const {
    return size;
}

template<typename Data>
Node<Data>* LinkedList<Data>::get_head() const {
    return head;
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
LinkedList<Data>::~LinkedList() {
    while (head != nullptr) {
        const Node<Data>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename Data>
LinkedList<Data>::LinkedList(const LinkedList<Data> &src) {
    Node<Data>* current = src.head;
    while (current != nullptr) {
        add_to_back(current->data);
        current = current->next;
    }
}

template<typename Data>
LinkedList<Data> &LinkedList<Data>::operator=(const LinkedList<Data> &src) {
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
}

template<typename Data>
LinkedList<Data>::LinkedList(LinkedList<Data> &&src) noexcept {
    head = src.head;
    size = src.size;

    src.head = nullptr;
    src.size = 0;
}

template<typename Data>
LinkedList<Data> &LinkedList<Data>::operator=(LinkedList<Data> &&src) noexcept {
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
}

template<typename Data>
LinkedList<Data>::LinkedList(std::initializer_list<Data> list) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        add_to_back(*it);
    }
}

#include "BinaryInsertionSort.tpp"

#endif //BINARYINSERTIONSORT_H
