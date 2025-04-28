//
// Created by aldin on 12/02/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/BinaryHeap.h"
#include <doctest/doctest.h>

TEST_CASE("Max binary heap") {
    SUBCASE("Inserting elements and checking max") {
        BinaryHeap<int> heap;
        heap.insert(10);
        heap.insert(20);
        heap.insert(5);
        heap.insert(30);

        CHECK_EQ(heap.peek(), 30);
    }

    SUBCASE("Deleting max from the heap") {
        BinaryHeap<int> heap{10, 20, 5, 30};

        CHECK_EQ(heap.poll(), 30);
        CHECK_EQ(heap.poll(), 20);
        CHECK_EQ(heap.poll(), 10);
        CHECK_EQ(heap.poll(), 5);
        CHECK(heap.is_empty());
    }

    SUBCASE("Heap property is maintained after multiple insertions") {
        BinaryHeap<int> heap;
        heap.insert(40);
        heap.insert(15);
        heap.insert(25);
        heap.insert(50);
        heap.insert(10);
        heap.insert(30);

        CHECK_EQ(heap.peek(), 50);
        heap.poll();
        CHECK_EQ(heap.peek(), 40);
        heap.poll();
        CHECK_EQ(heap.peek(), 30);
    }

    SUBCASE("Handling duplicate values") {
        BinaryHeap<int> heap;
        heap.insert(10);
        heap.insert(20);
        heap.insert(20);
        heap.insert(30);
        heap.insert(30);

        CHECK_EQ(heap.peek(), 30);
        heap.poll();
        CHECK_EQ(heap.peek(), 30);
        heap.poll();
        CHECK_EQ(heap.peek(), 20);
        heap.poll();
        CHECK_EQ(heap.peek(), 20);
    }

    SUBCASE("Heap operations on an initially empty heap") {
        BinaryHeap<int> heap;
        CHECK(heap.is_empty());

        heap.insert(5);
        CHECK_FALSE(heap.is_empty());

        CHECK_EQ(heap.poll(), 5);
        CHECK(heap.is_empty());
    }

    SUBCASE("Heap with floating point numbers") {
        BinaryHeap<double> heap{3.5, 1.2, 4.8, 2.9};

        CHECK_EQ(heap.poll(), 4.8);
        CHECK_EQ(heap.poll(), 3.5);
        CHECK_EQ(heap.poll(), 2.9);
        CHECK_EQ(heap.poll(), 1.2);
        CHECK(heap.is_empty());
    }

    SUBCASE("Heap with strings") {
        BinaryHeap<std::string> heap{"apple", "banana", "grape", "peach"};

        CHECK_EQ(heap.poll(), "peach");
        CHECK_EQ(heap.poll(), "grape");
        CHECK_EQ(heap.poll(), "banana");
        CHECK_EQ(heap.poll(), "apple");
        CHECK(heap.is_empty());
    }
}

TEST_CASE("Min binary heap") {
    SUBCASE("Inserting elements and checking min") {
        BinaryHeap<int> heap(false);
        heap.insert(10);
        heap.insert(20);
        heap.insert(5);
        heap.insert(30);

        CHECK_EQ(heap.peek(), 5);
    }

    SUBCASE("Deleting min from the heap") {
        BinaryHeap<int> heap({10, 20, 5, 30}, false);

        CHECK_EQ(heap.poll(), 5);
        CHECK_EQ(heap.poll(), 10);
        CHECK_EQ(heap.poll(), 20);
        CHECK_EQ(heap.poll(), 30);
        CHECK(heap.is_empty());
    }

    SUBCASE("Heap property is maintained after multiple insertions") {
        BinaryHeap<int> heap(false);
        heap.insert(40);
        heap.insert(15);
        heap.insert(25);
        heap.insert(50);
        heap.insert(10);
        heap.insert(30);

        CHECK_EQ(heap.peek(), 10);
        heap.poll();
        CHECK_EQ(heap.peek(), 15);
        heap.poll();
        CHECK_EQ(heap.peek(), 25);
    }

    SUBCASE("Handling duplicate values") {
        BinaryHeap<int> heap(false);
        heap.insert(20);
        heap.insert(10);
        heap.insert(20);
        heap.insert(10);
        heap.insert(30);

        CHECK_EQ(heap.peek(), 10);
        heap.poll();
        CHECK_EQ(heap.peek(), 10);
        heap.poll();
        CHECK_EQ(heap.peek(), 20);
        heap.poll();
        CHECK_EQ(heap.peek(), 20);
    }

    SUBCASE("Heap operations on an initially empty heap") {
        BinaryHeap<int> heap(false);
        CHECK(heap.is_empty());

        heap.insert(5);
        CHECK_FALSE(heap.is_empty());

        CHECK_EQ(heap.poll(), 5);
        CHECK(heap.is_empty());
    }

    SUBCASE("Heap with floating point numbers") {
        BinaryHeap<double> heap({3.5, 1.2, 4.8, 2.9}, false);

        CHECK_EQ(heap.poll(), 1.2);
        CHECK_EQ(heap.poll(), 2.9);
        CHECK_EQ(heap.poll(), 3.5);
        CHECK_EQ(heap.poll(), 4.8);
        CHECK(heap.is_empty());
    }

    SUBCASE("Heap with strings") {
        BinaryHeap<std::string> heap({"apple", "banana", "grape", "peach"}, false);

        CHECK_EQ(heap.poll(), "apple");
        CHECK_EQ(heap.poll(), "banana");
        CHECK_EQ(heap.poll(), "grape");
        CHECK_EQ(heap.poll(), "peach");
        CHECK(heap.is_empty());
    }
}

// Helper function that extracts all elements from a BinaryHeap into a vector,
// in the order returned by successive poll() calls.
template<typename Data>
std::vector<Data> extractHeap(BinaryHeap<Data> heap) {
    std::vector<Data> result;
    while (!heap.is_empty()) {
        result.push_back(heap.poll());
    }
    return result;
}

TEST_CASE("BinaryHeap copy semantics") {
    SUBCASE("BinaryHeap copy constructor") {
        BinaryHeap<int> original = {5, 3, 8, 1, 6};
        BinaryHeap<int> copy(original);

        // Both heaps should have the same size.
        CHECK_EQ(copy.size(), original.size());

        // Extract the deletion order from both heaps.
        auto originalOrder = extractHeap(original);
        auto copyOrder = extractHeap(copy);

        // The orders should be identical.
        CHECK_EQ(originalOrder, copyOrder);
    }

    SUBCASE("BinaryHeap copy assignment operator") {
        BinaryHeap<int> heap1 = {10, 20, 15};
        BinaryHeap<int> heap2 = {5, 1, 3};

        // Use copy assignment.
        heap2 = heap1;

        // Both heaps should now have the same size.
        CHECK_EQ(heap2.size(), heap1.size());

        // Extract deletion order from both heaps.
        auto order1 = extractHeap(heap1);
        auto order2 = extractHeap(heap2);

        // The deletion orders must be equal.
        CHECK_EQ(order1, order2);
    }
}

TEST_CASE("BinaryHeap move semantics") {
    SUBCASE("BinaryHeap move constructor") {
        BinaryHeap<int> original = {4, 9, 2, 7};
        int originalSize = original.size();

        // Move-construct a new heap from original.
        BinaryHeap<int> moved(std::move(original));

        // The moved-to object should have the original elements.
        CHECK(moved.size() == originalSize);

        // The original heap should be empty.
        CHECK(original.size() == 0);

        // Optionally, verify the deletion order of the moved heap.
        auto movedOrder = extractHeap(moved);
        // Since we know the input, we expect a descending order.
        std::vector<int> expected = movedOrder; // can't predict exact order easily,
        // but we check for consistency (e.g. non-increasing order).
        for (size_t i = 1; i < movedOrder.size(); i++) {
            CHECK(movedOrder[i-1] >= movedOrder[i]);
        }
    }

    SUBCASE("BinaryHeap move assignment operator") {
        BinaryHeap<int> heap1 = {11, 14, 9};
        BinaryHeap<int> heap2 = {1, 2, 3};
        int originalSize = heap1.size();

        // Use move assignment.
        heap2 = std::move(heap1);

        // The target heap should now have the original heap's elements.
        CHECK(heap2.size() == originalSize);

        // The moved-from heap should be empty.
        CHECK(heap1.size() == 0);

        // Verify that the deletion order in heap2 is non-increasing.
        auto order = extractHeap(heap2);
        for (size_t i = 1; i < order.size(); i++) {
            CHECK(order[i-1] >= order[i]);
        }
    }
}