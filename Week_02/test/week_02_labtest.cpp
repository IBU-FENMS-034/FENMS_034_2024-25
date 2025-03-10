//
// Created by aldin on 10/03/2025.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../include/DoublyLinkedList.h"
#include <stdexcept>
#include <string>

TEST_CASE("DoublyLinkedList comprehensive tests") {

    SUBCASE("Adding elements and checking head/tail assignments") {
        DoublyLinkedList<int> list;

        // Initially, the list should be empty and head/tail should be nullptr.
        CHECK_EQ(list.count(), 0);
        CHECK_EQ(list.get_front(), nullptr);
        CHECK_EQ(list.get_back(), nullptr);

        // Add to front; both head and tail should point to the single node.
        list.add_to_front(10);
        CHECK_EQ(list.count(), 1);
        CHECK_EQ(list[0], 10);
        CHECK_NE(list.get_front(), nullptr);
        CHECK_NE(list.get_back(), nullptr);
        CHECK_EQ(list.get_front(), list.get_back());

        // Add another element to the front.
        list.add_to_front(20);
        CHECK_EQ(list.count(), 2);
        CHECK_EQ(list[0], 20);
        CHECK_EQ(list[1], 10);
        // Head should now be 20, and tail should remain 10.
        CHECK_EQ(list.get_front()->data, 20);
        CHECK_EQ(list.get_back()->data, 10);

        // Add to back.
        list.add_to_back(30);
        CHECK_EQ(list.count(), 3);
        CHECK_EQ(list[0], 20);
        CHECK_EQ(list[1], 10);
        CHECK_EQ(list[2], 30);
        // Head should remain 20, tail should now be 30.
        CHECK_EQ(list.get_front()->data, 20);
        CHECK_EQ(list.get_back()->data, 30);
    }

    SUBCASE("Removing elements from front and back updates head/tail correctly") {
        DoublyLinkedList<int> list{1, 2, 3, 4};

        // Initially, head should be 1 and tail should be 4.
        CHECK_EQ(list.get_front()->data, 1);
        CHECK_EQ(list.get_back()->data, 4);

        // Remove from front, new head should be 2.
        list.remove_from_front();
        CHECK_EQ(list.count(), 3);
        CHECK_EQ(list.get_front()->data, 2);

        // Remove from back, new tail should be 3.
        list.remove_from_back();
        CHECK_EQ(list.count(), 2);
        CHECK_EQ(list.get_back()->data, 3);

        // Remove remaining elements to ensure pointers become nullptr.
        list.remove_from_front();
        list.remove_from_back();
        CHECK_EQ(list.count(), 0);
        CHECK_EQ(list.get_front(), nullptr);
        CHECK_EQ(list.get_back(), nullptr);
    }

    SUBCASE("Initializer list constructor with correct head/tail") {
        DoublyLinkedList<int> list{5, 10, 15};
        CHECK_EQ(list.count(), 3);
        // Head should be first element (5) and tail should be last element (15).
        CHECK_EQ(list[0], 5);
        CHECK_EQ(list[1], 10);
        CHECK_EQ(list[2], 15);
        CHECK_EQ(list.get_front()->data, 5);
        CHECK_EQ(list.get_back()->data, 15);
    }

    SUBCASE("Copy constructor and copy assignment preserve head/tail assignments") {
        DoublyLinkedList<int> original{100, 200, 300};

        // Copy constructor
        DoublyLinkedList<int> copyConstructed(original);
        CHECK_EQ(copyConstructed.count(), original.count());
        CHECK_EQ(copyConstructed.get_front()->data, original.get_front()->data);
        CHECK_EQ(copyConstructed.get_back()->data, original.get_back()->data);
        for (int i = 0; i < original.count(); i++) {
            CHECK_EQ(original[i], copyConstructed[i]);
        }

        // Copy assignment operator
        DoublyLinkedList<int> copyAssigned;
        copyAssigned = original;
        CHECK_EQ(copyAssigned.count(), original.count());
        CHECK_EQ(copyAssigned.get_front()->data, original.get_front()->data);
        CHECK_EQ(copyAssigned.get_back()->data, original.get_back()->data);
        for (int i = 0; i < original.count(); i++) {
            CHECK_EQ(original[i], copyAssigned[i]);
        }
    }

    SUBCASE("Move constructor and move assignment update head/tail correctly") {
        DoublyLinkedList<int> original{1, 2, 3};

        // Move constructor: after moving, original should be empty.
        DoublyLinkedList<int> movedConstructed(std::move(original));
        CHECK_EQ(movedConstructed.count(), 3);
        CHECK_EQ(movedConstructed.get_front()->data, 1);
        CHECK_EQ(movedConstructed.get_back()->data, 3);
        CHECK_EQ(original.count(), 0);
        CHECK_EQ(original.get_front(), nullptr);
        CHECK_EQ(original.get_back(), nullptr);

        // Move assignment operator
        DoublyLinkedList<int> another{4, 5, 6};
        DoublyLinkedList<int> movedAssigned;
        movedAssigned = std::move(another);
        CHECK_EQ(movedAssigned.count(), 3);
        CHECK_EQ(movedAssigned.get_front()->data, 4);
        CHECK_EQ(movedAssigned.get_back()->data, 6);
        CHECK_EQ(another.count(), 0);
        CHECK_EQ(another.get_front(), nullptr);
        CHECK_EQ(another.get_back(), nullptr);
    }

    SUBCASE("Reverse list functionality updates head/tail") {
        DoublyLinkedList<int> list{1, 2, 3, 4, 5};
        // Before reverse: head is 1, tail is 5.
        CHECK_EQ(list.get_front()->data, 1);
        CHECK_EQ(list.get_back()->data, 5);
        list.reverse();
        // After reverse: head should be 5 and tail should be 1.
        CHECK_EQ(list.get_front()->data, 5);
        CHECK_EQ(list.get_back()->data, 1);
        // And the overall ordering is reversed.
        CHECK_EQ(list[0], 5);
        CHECK_EQ(list[list.count() - 1], 1);
    }

    SUBCASE("Get method works correctly") {
        DoublyLinkedList<int> list{10, 20, 30};
        CHECK_EQ(list.get(0), 10);
        CHECK_EQ(list.get(1), 20);
        CHECK_EQ(list.get(2), 30);
    }

    SUBCASE("Iterator functionality") {
        DoublyLinkedList<int> list{1, 2, 3, 4};
        int sum = 0;
        for(auto it = list.begin(); it != list.end(); ++it) {
            sum += *it;
        }
        CHECK_EQ(sum, 10);
    }
}