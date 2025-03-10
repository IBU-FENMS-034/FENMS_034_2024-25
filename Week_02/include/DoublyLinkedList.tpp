//
// Created by aldin on 10/03/2025.
//

#ifndef DOUBLYLINKEDLIST_TPP
#define DOUBLYLINKEDLIST_TPP

// used for tests, DO NOT REMOVE
template <typename Data>
DoubleNode<Data>* DoublyLinkedList<Data>::get_front() const {
    return head;
}

template <typename Data>
DoubleNode<Data>* DoublyLinkedList<Data>::get_back() const {
    return tail;
}

// Your code below this line

#endif //DOUBLYLINKEDLIST_TPP
