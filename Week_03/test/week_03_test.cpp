//
// Created by aldin on 16/03/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/Stack.h"
#include "../include/Queue.h"
#include <doctest/doctest.h>
#include <cmath>

//---------------------------------------------------
//                   Stack Tests
//---------------------------------------------------
TEST_CASE("Stack Tests") {
    SUBCASE("Empty Stack") {
        Stack<int> s;
        CHECK(s.is_empty());
        CHECK_EQ(s.size(), 0);
        CHECK_THROWS_AS(s.pop(), std::out_of_range);
        CHECK_THROWS_AS(s.peek(), std::out_of_range);
    }

    SUBCASE("Push and Peek") {
        Stack<int> s;
        s.push(10);
        CHECK_FALSE(s.is_empty());
        CHECK_EQ(s.size(), 1);
        CHECK_EQ(s.peek(), 10);
        s.push(20);
        CHECK_EQ(s.size(), 2);
        CHECK_EQ(s.peek(), 20);
    }

    SUBCASE("Push and Pop") {
        Stack<int> s;
        s.push(5);
        s.push(15);
        s.push(25);
        CHECK_EQ(s.size(), 3);
        CHECK_EQ(s.pop(), 25);
        CHECK_EQ(s.pop(), 15);
        CHECK_EQ(s.pop(), 5);
        CHECK(s.is_empty());
    }

    SUBCASE("Initializer List Construction") {
        Stack<int> s {100, 200, 300};  // Order: top = 300, bottom = 100
        CHECK_EQ(s.size(), 3);
        CHECK_EQ(s.peek(), 300);
        CHECK_EQ(s.pop(), 300);
        CHECK_EQ(s.pop(), 200);
        CHECK_EQ(s.pop(), 100);
    }

    SUBCASE("Reverse Operation") {
        // Create a stack with initializer list; note that push in initializer_list
        // order is from first element to last.
        Stack<int> s {1, 2, 3, 4, 5}; // Because push() is used in initializer_list, the top will be the last element.
        CHECK_EQ(s.size(), 5);
        s.reverse();
        // Popping should yield 1 then 2 then 3, etc.
        CHECK_EQ(s.pop(), 1);
        CHECK_EQ(s.pop(), 2);
        CHECK_EQ(s.pop(), 3);
        CHECK_EQ(s.pop(), 4);
        CHECK_EQ(s.pop(), 5);
    }

    SUBCASE("Copy Semantics") {
        Stack<int> original;
        original.push(100);
        original.push(200);
        original.push(300);

        SUBCASE("Copy Constructor") {
            Stack<int> copyConstructed(original);
            CHECK_EQ(copyConstructed.size(), original.size());
            // Popping from the copy should yield the same order as from original.
            CHECK_EQ(copyConstructed.pop(), 300);
            CHECK_EQ(copyConstructed.pop(), 200);
            CHECK_EQ(copyConstructed.pop(), 100);
        }

        SUBCASE("Copy Assignment") {
            Stack<int> copyAssigned;
            copyAssigned = original;
            CHECK_EQ(copyAssigned.size(), original.size());
            CHECK_EQ(copyAssigned.pop(), 300);
            CHECK_EQ(copyAssigned.pop(), 200);
            CHECK_EQ(copyAssigned.pop(), 100);
        }
    }

    SUBCASE("Move Semantics") {
        SUBCASE("Move Constructor") {
            Stack<int> original;
            original.push(7);
            original.push(8);
            original.push(9);

            Stack<int> moved(std::move(original));
            CHECK_EQ(moved.size(), 3);
            CHECK_EQ(moved.pop(), 9);
            CHECK_EQ(moved.pop(), 8);
            CHECK_EQ(moved.pop(), 7);
            CHECK(moved.is_empty());
            // Original should be empty after move
            CHECK_EQ(original.size(), 0);
        }

        SUBCASE("Move Assignment") {
            Stack<int> original;
            original.push(11);
            original.push(22);
            original.push(33);

            Stack<int> moved;
            moved = std::move(original);
            CHECK_EQ(moved.size(), 3);
            CHECK_EQ(moved.pop(), 33);
            CHECK_EQ(moved.pop(), 22);
            CHECK_EQ(moved.pop(), 11);
            CHECK(moved.is_empty());
            // Original should be empty after move
            CHECK_EQ(original.size(), 0);
        }
    }
}

//---------------------------------------------------
//                   Queue Tests
//---------------------------------------------------
TEST_CASE("Queue Tests") {
    SUBCASE("Empty Queue") {
        Queue<int> q;
        CHECK(q.is_empty());
        CHECK_EQ(q.size(), 0);
        CHECK_THROWS_AS(q.dequeue(), std::out_of_range);
        CHECK_THROWS_AS(q.peek(), std::out_of_range);
    }

    SUBCASE("Enqueue and Peek") {
        Queue<int> q;
        q.enqueue(10);
        CHECK_FALSE(q.is_empty());
        CHECK_EQ(q.size(), 1);
        CHECK_EQ(q.peek(), 10);
        q.enqueue(20);
        CHECK_EQ(q.size(), 2);
        // peek() should always return the front element.
        CHECK_EQ(q.peek(), 10);
    }

    SUBCASE("Enqueue and Dequeue") {
        Queue<int> q;
        q.enqueue(5);
        q.enqueue(15);
        q.enqueue(25);
        CHECK_EQ(q.size(), 3);
        CHECK_EQ(q.dequeue(), 5);
        CHECK_EQ(q.dequeue(), 15);
        CHECK_EQ(q.dequeue(), 25);
        CHECK(q.is_empty());
    }

    SUBCASE("Initializer List Construction") {
        Queue<int> q {100, 200, 300};  // Order: head = 100, tail = 300
        CHECK_EQ(q.size(), 3);
        CHECK_EQ(q.peek(), 100);
        CHECK_EQ(q.dequeue(), 100);
        CHECK_EQ(q.dequeue(), 200);
        CHECK_EQ(q.dequeue(), 300);
    }

    SUBCASE("Reverse Operation") {
        // Create a queue with initializer list
        Queue<int> q {1, 2, 3, 4, 5};
        // After construction (via initializer_list), the order should be preserved.
        CHECK_EQ(q.size(), 5);
        q.reverse();

        CHECK_EQ(q.dequeue(), 5);
        CHECK_EQ(q.dequeue(), 4);
        CHECK_EQ(q.dequeue(), 3);
        CHECK_EQ(q.dequeue(), 2);
        CHECK_EQ(q.dequeue(), 1);
    }

    SUBCASE("Copy Semantics") {
        Queue<int> original;
        original.enqueue(1);
        original.enqueue(2);
        original.enqueue(3);

        SUBCASE("Copy Constructor") {
            Queue<int> copyConstructed(original);
            CHECK_EQ(copyConstructed.size(), original.size());
            // Dequeue from the copy should yield the same order as original.
            CHECK_EQ(copyConstructed.dequeue(), 1);
            CHECK_EQ(copyConstructed.dequeue(), 2);
            CHECK_EQ(copyConstructed.dequeue(), 3);
        }

        SUBCASE("Copy Assignment") {
            Queue<int> copyAssigned;
            copyAssigned = original;
            CHECK_EQ(copyAssigned.size(), original.size());
            CHECK_EQ(copyAssigned.dequeue(), 1);
            CHECK_EQ(copyAssigned.dequeue(), 2);
            CHECK_EQ(copyAssigned.dequeue(), 3);
        }
    }

    SUBCASE("Move Semantics") {
        SUBCASE("Move Constructor") {
            Queue<int> original;
            original.enqueue(7);
            original.enqueue(8);
            original.enqueue(9);

            Queue<int> moved(std::move(original));
            CHECK_EQ(moved.size(), 3);
            CHECK_EQ(moved.dequeue(), 7);
            CHECK_EQ(moved.dequeue(), 8);
            CHECK_EQ(moved.dequeue(), 9);
            CHECK(moved.is_empty());
            // Original should be empty after move.
            CHECK_EQ(original.size(), 0);
        }

        SUBCASE("Move Assignment") {
            Queue<int> original;
            original.enqueue(11);
            original.enqueue(22);
            original.enqueue(33);

            Queue<int> moved;
            moved = std::move(original);
            CHECK_EQ(moved.size(), 3);
            CHECK_EQ(moved.dequeue(), 11);
            CHECK_EQ(moved.dequeue(), 22);
            CHECK_EQ(moved.dequeue(), 33);
            CHECK(moved.is_empty());
            // Original should be empty after move.
            CHECK_EQ(original.size(), 0);
        }
    }
};