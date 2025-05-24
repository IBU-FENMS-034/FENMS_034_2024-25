//
// Created by aldin on 13/02/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../include/RedBlackTree.h"

TEST_CASE("Red-black tree - basic operations") {
    SUBCASE("Insert and Get Values") {
        RedBlackTree<int, std::string> rbt;
        rbt.put(5, "five");
        rbt.put(3, "three");
        rbt.put(7, "seven");
        rbt.put(2, "two");
        rbt.put(4, "four");

        CHECK_EQ(rbt.get(5), "five");
        CHECK_EQ(rbt.get(3), "three");
        CHECK_EQ(rbt.get(7), "seven");
        CHECK_EQ(rbt.get(2), "two");
        CHECK_EQ(rbt.get(4), "four");

        // Test non-existing key
        CHECK_EQ(rbt.get(10), "");  // Default-constructed Value (std::string{})
    }

    SUBCASE("Find min") {
        RedBlackTree<int, std::string> rbt{{10, "ten"}, {5, "five"}, {20, "twenty"}, {2, "two"}, {8, "eight"}};

        CHECK_EQ(rbt.find_min(), 2);
    }

    SUBCASE("Tree size calculation") {
        RedBlackTree<int, std::string> rbt;
        CHECK_EQ(rbt.size(), 0);

        rbt.put(10, "ten");
        CHECK_EQ(rbt.size(), 1);

        rbt.put(5, "five");
        rbt.put(15, "fifteen");
        CHECK_EQ(rbt.size(), 3);
    }
}

TEST_CASE("Red-Black Tree - Deletion") {
    SUBCASE("Delete minimum key") {
        RedBlackTree<int, std::string> rbt{{5, "five"}, {3, "three"}, {7, "seven"}, {2, "two"}, {4, "four"}};

        rbt.delete_min();
        CHECK_EQ(rbt.find_min(), 3);
    }

    SUBCASE("Delete any key") {
        RedBlackTree<int, std::string> rbt{{10, "ten"}, {5, "five"}, {15, "fifteen"}, {3, "three"}, {7, "seven"}, {9, "nine"}};

        rbt.delete_any(5);
        CHECK_EQ(rbt.get(5), "");  // Should return default value
        CHECK_EQ(rbt.find_min(), 3);
    }
}

TEST_CASE("RedBlackTree copy semantics") {
    SUBCASE("Copy constructor") {
        // Create an original red–black tree with some key/value pairs.
        RedBlackTree<int, int> original({ {5,50}, {3,30}, {8,80}, {1,10}, {6,60} });
        // Use the copy constructor.
        RedBlackTree<int, int> copy(original);

        // Both trees should have the same size.
        CHECK_EQ(copy.size(), original.size());

        // Check that the values associated with each key are identical.
        CHECK_EQ(copy.get(5), 50);
        CHECK_EQ(copy.get(3), 30);
        CHECK_EQ(copy.get(8), 80);
        CHECK_EQ(copy.get(1), 10);
        CHECK_EQ(copy.get(6), 60);
    }

    SUBCASE("Copy assignment operator") {
        RedBlackTree<int, int> tree1({ {10,100}, {20,200}, {15,150} });
        RedBlackTree<int, int> tree2({ {5,50}, {1,10}, {3,30} });

        // Use copy assignment.
        tree2 = tree1;

        // Both trees should now have the same size.
        CHECK_EQ(tree2.size(), tree1.size());

        // Check that the key/value associations match.
        CHECK_EQ(tree2.get(10), 100);
        CHECK_EQ(tree2.get(20), 200);
        CHECK_EQ(tree2.get(15), 150);
    }
}

TEST_CASE("RedBlackTree move semantics") {
    SUBCASE("Move constructor") {
        RedBlackTree<int, int> original({ {4,40}, {9,90}, {2,20}, {7,70} });
        int originalSize = original.size();

        // Move-construct a new tree from original.
        RedBlackTree<int, int> moved(std::move(original));

        // The moved-to tree should have the original elements.
        CHECK_EQ(moved.size(), originalSize);
        // The moved-from tree should be empty.
        CHECK_EQ(original.size(), 0);

        // Verify that the moved tree returns the expected values.
        CHECK_EQ(moved.get(4), 40);
        CHECK_EQ(moved.get(9), 90);
        CHECK_EQ(moved.get(2), 20);
        CHECK_EQ(moved.get(7), 70);
    }

    SUBCASE("Move assignment operator") {
        RedBlackTree<int, int> tree1({ {11,110}, {14,140}, {9,90} });
        RedBlackTree<int, int> tree2({ {1,10}, {2,20}, {3,30} });
        int tree1Size = tree1.size();

        // Use move assignment.
        tree2 = std::move(tree1);

        // The moved-from tree should now be empty.
        CHECK_EQ(tree1.size(), 0);
        // The moved-to tree should have the elements originally in tree1.
        CHECK_EQ(tree2.size(), tree1Size);

        // Check that the key/value pairs in the moved tree are correct.
        CHECK_EQ(tree2.get(11), 110);
        CHECK_EQ(tree2.get(14), 140);
        CHECK_EQ(tree2.get(9), 90);
    }
}