//
// Created by aldin on 12/02/2025.
//

#include "../include/BinaryHeap.h"
#include <iostream>

void max_heap_demo();
void min_heap_demo();

int main() {
    max_heap_demo();
    std::cout << std::endl;
    min_heap_demo();
}

void max_heap_demo() {
    BinaryHeap<int> heap;

    heap.insert(4);
    heap.insert(10);
    heap.insert(-5);
    heap.insert(7);

    std::cout << "Max heap demo: " << std::endl;
    std::cout << "Heap size: " << heap.size() << std::endl;
    std::cout << "Is empty? " << heap.is_empty() << std::endl;
    std::cout << "Current max. element (peek): " << heap.peek() << std::endl;
    std::cout << "Current max. element (delete): " << heap.poll() << std::endl;
    std::cout << "Current max. element (delete): " << heap.poll() << std::endl;
    std::cout << "Current max. element (delete): " << heap.poll() << std::endl;
    std::cout << "Heap size: " << heap.size() << std::endl;
    std::cout << "Current max. element (delete): " << heap.poll() << std::endl;

    // Initializer list
    std::cout << std::endl;
    BinaryHeap<int> heap2{6, 3, 12, -5, 7};
    std::cout << "Heap size: " << heap2.size() << std::endl;
    std::cout << "Current max. element (delete): " << heap2.poll() << std::endl;
    std::cout << "Current max. element (delete): " << heap2.poll() << std::endl;
}

void min_heap_demo() {
    BinaryHeap<int> heap(false);

    heap.insert(4);
    heap.insert(10);
    heap.insert(-5);
    heap.insert(7);

    std::cout << "Min heap demo: " << std::endl;
    std::cout << "Heap size: " << heap.size() << std::endl;
    std::cout << "Is empty? " << heap.is_empty() << std::endl;
    std::cout << "Current min. element (peek): " << heap.peek() << std::endl;
    std::cout << "Current min. element (delete): " << heap.poll() << std::endl;
    std::cout << "Current min. element (delete): " << heap.poll() << std::endl;
    std::cout << "Current min. element (delete): " << heap.poll() << std::endl;
    std::cout << "Heap size: " << heap.size() << std::endl;
    std::cout << "Current min. element (delete): " << heap.poll() << std::endl;

    // Initializer list
    std::cout << std::endl;
    BinaryHeap<int> heap2({6, 3, 12, -5, 7}, false);
    std::cout << "Heap size: " << heap2.size() << std::endl;
    std::cout << "Current min. element (delete): " << heap2.poll() << std::endl;
    std::cout << "Current min. element (delete): " << heap2.poll() << std::endl;
}
