//
// Created by aldin on 10/03/2025.
//

#include <iostream>
#include "../include/LinkedList.h"

void linked_list_demo();
void semantics_demo();

int main() {
    linked_list_demo();
    std::cout << std::endl;
    semantics_demo();
    std::cout << std::endl;
}

void linked_list_demo() {
    std::cout << "Linked list demo:" << std::endl;
    LinkedList<int> list;

    list.add_to_back(1);
    list.add_to_back(2);
    list.add_to_back(3);
    list.add_to_back(4);
    list.add_to_front(5);
    list.add_to_front(6);

    list.remove_from_back();
    list.remove_from_front();

    std::cout << "List is: " << std::endl;
    for (const int i: list) {
        std::cout << i << std::endl;
    }

    std::cout << "Element at 0: " << list.get(0) << std::endl;
    std::cout << "Element at 1: " << list.get(1) << std::endl;
    std::cout << "List size: " << list.count() << std::endl;

    std::cout << "Testing array-style access: " << std::endl;
    std::cout << "- Element at 1 before assignment: " << list[1] << std::endl;
    list[1] = 42;
    std::cout << "- Element at 1 after assignment: " << list[1] << std::endl;

    std::cout << "Reversing the list:" << std::endl;
    list.reverse();
    for (const int i: list) {
        std::cout << i << std::endl;
    }
}

void semantics_demo() {
    LinkedList<int> list; // default constructor
    LinkedList<int> list2{1, 2, 3, 4}; // list initializer constructor
    LinkedList<int> list3(list2); // copy constructor
    LinkedList<int> list4 = list3; // copy constructor
    LinkedList<int> list5; // default constructor
    list5 = list4; // copy assignment
    LinkedList<int> list6; // default constructor
    list6 = {1, 2, 3, 4}; // list initializer + move assignment
    LinkedList<int> list7(std::move(list6)); // move constructor
    LinkedList<int> list8 = std::move(list7); // move constructor
    LinkedList<int> list9; // default constructor
    list9 = std::move(list8); // move assignment
}