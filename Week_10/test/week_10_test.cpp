//
// Created by aldin on 12/02/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../include/BinarySearchTree.h"  // Adjust path as needed

TEST_CASE("Binary search tree - basic operations") {
    SUBCASE("Insert and get values") {
        BinarySearchTree<int, std::string> bst;
        bst.put(5, "five");
        bst.put(3, "three");
        bst.put(7, "seven");
        bst.put(2, "two");
        bst.put(4, "four");

        CHECK_EQ(bst.get(5), "five");
        CHECK_EQ(bst.get(3), "three");
        CHECK_EQ(bst.get(7), "seven");
        CHECK_EQ(bst.get(2), "two");
        CHECK_EQ(bst.get(4), "four");

        // Test non-existing key
        CHECK_EQ(bst.get(10), "");  // Default-constructed Value (std::string{})
    }

    SUBCASE("Find min and max") {
        BinarySearchTree<int, std::string> bst{{10, "ten"}, {5, "five"}, {20, "twenty"}, {2, "two"}, {8, "eight"}};

        CHECK_EQ(bst.find_min(), 2);
        CHECK_EQ(bst.find_max(), 20);
    }

    SUBCASE("Tree size calculation") {
        BinarySearchTree<int, std::string> bst;
        CHECK_EQ(bst.size(), 0);

        bst.put(10, "ten");
        CHECK_EQ(bst.size(), 1);

        bst.put(5, "five");
        bst.put(15, "fifteen");
        CHECK_EQ(bst.size(), 3);
    }

    SUBCASE("Rank calculation") {
        BinarySearchTree<int, std::string> bst{{10, "ten"}, {5, "five"}, {15, "fifteen"}, {3, "three"}, {7, "seven"}};

        CHECK_EQ(bst.rank(3), 0);
        CHECK_EQ(bst.rank(5), 1);
        CHECK_EQ(bst.rank(7), 2);
        CHECK_EQ(bst.rank(10), 3);
        CHECK_EQ(bst.rank(15), 4);
    }
}

TEST_CASE("Binary search tree - deletion") {
    SUBCASE("Delete minimum key") {
        BinarySearchTree<int, std::string> bst{{5, "five"}, {3, "three"}, {7, "seven"}, {2, "two"}, {4, "four"}};

        bst.delete_min();
        CHECK_EQ(bst.find_min(), 3);
    }

    SUBCASE("Delete any key") {
        BinarySearchTree<int, std::string> bst{{10, "ten"}, {5, "five"}, {15, "fifteen"}, {3, "three"}, {7, "seven"}, {9, "nine"}};

        bst.delete_any(5);
        CHECK_EQ(bst.get(5), "");  // Should return default value
        CHECK_EQ(bst.find_min(), 3);
    }
}

TEST_CASE("Binary search tree - traversal") {
    BinarySearchTree<int, std::string> bst{{10, "ten"}, {5, "five"}, {15, "fifteen"}, {3, "three"}, {7, "seven"}};

    SUBCASE("Inorder traversal") {
        std::stringstream output;
        std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

        bst.inorder();

        std::cout.rdbuf(oldCout);  // Restore original stdout
        CHECK_EQ(output.str(), "3 5 7 10 15 ");
    }

    SUBCASE("Preorder traversal") {
        std::stringstream output;
        std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

        bst.preorder();

        std::cout.rdbuf(oldCout);  // Restore original stdout
        CHECK_EQ(output.str(), "10 5 3 7 15 ");
    }

    SUBCASE("Postorder traversal") {
        std::stringstream output;
        std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

        bst.postorder();

        std::cout.rdbuf(oldCout);  // Restore original stdout
        CHECK_EQ(output.str(), "3 7 5 15 10 ");
    }
}

// Helper: Capture the output of the inorder() method.
template<typename Key, typename Value>
std::string captureInorder(BinarySearchTree<Key, Value>& bst) {
    std::stringstream ss;
    auto oldBuf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    bst.inorder();
    std::cout.rdbuf(oldBuf);
    return ss.str();
}

TEST_CASE("BinarySearchTree copy semantics") {
    SUBCASE("Copy constructor") {
        // Create an original BST with several key/value pairs.
        BinarySearchTree<int, int> original({ {5,50}, {3,30}, {8,80}, {1,10}, {6,60} });
        // Copy-construct a new tree.
        BinarySearchTree<int, int> copy(original);

        // Both trees should have the same size.
        CHECK_EQ(copy.size(), original.size());

        // Capture the inorder traversal output from both trees.
        std::string originalInorder = captureInorder(original);
        std::string copyInorder = captureInorder(copy);

        // The inorder outputs must be identical.
        CHECK_EQ(copyInorder, originalInorder);
    }

    SUBCASE("Copy assignment operator") {
        BinarySearchTree<int, int> tree1({ {10,100}, {20,200}, {15,150} });
        BinarySearchTree<int, int> tree2({ {5,50}, {1,10}, {3,30} });

        // Use copy assignment.
        tree2 = tree1;

        // Both trees should now have the same size.
        CHECK_EQ(tree2.size(), tree1.size());

        // Capture inorder traversal output from both trees.
        std::string inorder1 = captureInorder(tree1);
        std::string inorder2 = captureInorder(tree2);

        // The inorder outputs must be equal.
        CHECK_EQ(inorder1, inorder2);
    }
}

TEST_CASE("BinarySearchTree move semantics") {
    SUBCASE("Move constructor") {
        BinarySearchTree<int, int> original({ {4,40}, {9,90}, {2,20}, {7,70} });
        // Capture original's inorder output.
        std::string originalInorder = captureInorder(original);
        int originalSize = original.size();

        // Move-construct a new tree from original.
        BinarySearchTree<int, int> moved(std::move(original));

        // The moved-to tree should have the original size.
        CHECK_EQ(moved.size(), originalSize);

        // The moved-from tree should be empty.
        CHECK_EQ(original.size(), 0);

        // Capture inorder output from the moved tree.
        std::string movedInorder = captureInorder(moved);
        CHECK_EQ(movedInorder, originalInorder);
    }

    SUBCASE("Move assignment operator") {
        BinarySearchTree<int, int> tree1({ {11,110}, {14,140}, {9,90} });
        BinarySearchTree<int, int> tree2({ {1,10}, {2,20}, {3,30} });
        // Capture tree1's inorder output.
        std::string tree1Inorder = captureInorder(tree1);
        int tree1Size = tree1.size();

        // Use move assignment.
        tree2 = std::move(tree1);

        // The moved-from tree should be empty.
        CHECK_EQ(tree1.size(), 0);
        // The target tree should now have the original elements.
        CHECK_EQ(tree2.size(), tree1Size);

        // Capture tree2's inorder output.
        std::string tree2Inorder = captureInorder(tree2);
        CHECK_EQ(tree2Inorder, tree1Inorder);
    }
}