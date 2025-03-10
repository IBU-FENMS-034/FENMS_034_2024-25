//
// Created by aldin on 10/03/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../include/LinkedList.h"
#include <stdexcept>
#include <string>

//--- Basic Operations ---//
TEST_CASE("LinkedList basic operations") {
    LinkedList<int> list;

    SUBCASE("Empty list") {
        CHECK_EQ(list.count(), 0);
        CHECK_THROWS_AS(list.remove_from_front(), std::out_of_range);
        CHECK_THROWS_AS(list.remove_from_back(), std::out_of_range);
    }

    SUBCASE("Add and access elements") {
        list.add_to_front(10);  // List: 10
        CHECK_EQ(list.count(), 1);
        CHECK_EQ(list[0], 10);

        list.add_to_back(20);   // List: 10, 20
        CHECK_EQ(list.count(), 2);
        CHECK_EQ(list[1], 20);

        list.add_to_front(5);   // List: 5, 10, 20
        CHECK_EQ(list.count(), 3);
        CHECK_EQ(list[0], 5);
        CHECK_EQ(list[1], 10);
        CHECK_EQ(list[2], 20);

        // Verify get() method
        CHECK_EQ(list.get(0), 5);
        CHECK_EQ(list.get(1), 10);
        CHECK_EQ(list.get(2), 20);
    }

    SUBCASE("Remove elements") {
        // Setup list: 5, 10, 20
        list.add_to_front(10);
        list.add_to_back(20);
        list.add_to_front(5);

        list.remove_from_front(); // Removes 5; list becomes: 10, 20
        CHECK_EQ(list.count(), 2);
        CHECK_EQ(list[0], 10);
        CHECK_EQ(list[1], 20);

        list.remove_from_back();  // Removes 20; list becomes: 10
        CHECK_EQ(list.count(), 1);
        CHECK_EQ(list[0], 10);
    }
}

//--- Iterator Functionality ---//
TEST_CASE("LinkedList iterator") {
    LinkedList<int> list;
    list.add_to_back(100);
    list.add_to_back(200);
    list.add_to_back(300);

    int expected[] = {100, 200, 300};
    int idx = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        CHECK_EQ(*it, expected[idx++]);
    }
}

//--- Reverse Operation ---//
TEST_CASE("LinkedList reverse") {
    LinkedList<int> list;
    // Create list: 0, 1, 2, 3, 4
    for (int i = 0; i < 5; ++i) {
        list.add_to_back(i);
    }
    list.reverse();
    // After reverse, list should be: 4, 3, 2, 1, 0
    for (int i = 0; i < 5; ++i) {
        CHECK_EQ(list[i], 4 - i);
    }
}

//--- Initializer List Construction ---//
TEST_CASE("LinkedList initializer list") {
    LinkedList<int> list {10, 20, 30};
    CHECK_EQ(list.count(), 3);
    CHECK_EQ(list[0], 10);
    CHECK_EQ(list[1], 20);
    CHECK_EQ(list[2], 30);
}

//--- Copy Semantics ---//
TEST_CASE("LinkedList copy semantics") {
    LinkedList<int> original;
    original.add_to_back(1);
    original.add_to_back(2);
    original.add_to_back(3);

    SUBCASE("Copy Constructor") {
        LinkedList<int> copyConstructed(original);
        CHECK_EQ(copyConstructed.count(), original.count());
        for (int i = 0; i < original.count(); ++i) {
            CHECK_EQ(copyConstructed[i], original[i]);
        }
    }

    SUBCASE("Copy Assignment") {
        LinkedList<int> copyAssigned;
        copyAssigned = original;
        CHECK_EQ(copyAssigned.count(), original.count());
        for (int i = 0; i < original.count(); ++i) {
            CHECK_EQ(copyAssigned[i], original[i]);
        }
    }
}

//--- Move Semantics ---//
TEST_CASE("LinkedList move semantics") {
    SUBCASE("Move Constructor") {
        LinkedList<int> original;
        original.add_to_back(4);
        original.add_to_back(5);
        original.add_to_back(6);

        // Move-construct a new list from original.
        LinkedList<int> moved(std::move(original));
        CHECK_EQ(moved.count(), 3);
        CHECK_EQ(moved[0], 4);
        CHECK_EQ(moved[1], 5);
        CHECK_EQ(moved[2], 6);

        // The original list should now be empty.
        CHECK_EQ(original.count(), 0);
    }

    SUBCASE("Move Assignment") {
        LinkedList<int> original;
        original.add_to_back(7);
        original.add_to_back(8);
        original.add_to_back(9);

        LinkedList<int> moved;
        moved = std::move(original);
        CHECK_EQ(moved.count(), 3);
        CHECK_EQ(moved[0], 7);
        CHECK_EQ(moved[1], 8);
        CHECK_EQ(moved[2], 9);

        // The original list should be empty after the move.
        CHECK_EQ(original.count(), 0);
    }
}