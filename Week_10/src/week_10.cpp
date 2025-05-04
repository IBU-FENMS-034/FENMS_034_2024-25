//
// Created by aldin on 12/02/2025.
//

#include <iostream>
#include <string>

#include "../include/BinarySearchTree.h"

int main() {
    BinarySearchTree<char, int> bst;

    bst.put('T', 1);
    bst.put('E', 2);
    bst.put('X', 3);
    bst.put('A', 4);
    bst.put('R', 5);
    bst.put('C', 6);
    bst.put('H', 7);
    bst.put('M', 8);

    std::cout << "Key R holds value: " << bst.get('R') << std::endl;
    std::cout << "Key M holds value: " << bst.get('M') << std::endl;
    std::cout << "Key X holds value: " << bst.get('X') << std::endl;
    std::cout << "Key Z (non-existent) holds value: " << bst.get('Z') << std::endl;

    std::cout << "Size of tree: " << bst.size() << std::endl;

    std::cout << "Min key: " << bst.find_min() << std::endl;
    std::cout << "Max key: " << bst.find_max() << std::endl;

    std::cout << "Rank of E: " << bst.rank('E') << std::endl;
    std::cout << "Rank of R: " << bst.rank('R') << std::endl;

    bst.delete_min();
    std::cout << "Min key after min deletion: " << bst.find_min() << std::endl;
    std::cout << "Size of tree after min deletion: " << bst.size() << std::endl;

    bst.delete_any('H');
    bst.delete_any('M');
    std::cout << "Key M holds value: " << bst.get('M') << std::endl;
    std::cout << "Size of tree after deletion: " << bst.size() << std::endl;

    std::cout << std::endl;
    std::cout << "Inorder traversal: " << std::endl;
    bst.inorder();

    std::cout << std::endl;
    std::cout << "Preorder traversal: " << std::endl;
    bst.preorder();

    std::cout << std::endl;
    std::cout << "Postorder traversal: " << std::endl;
    bst.postorder();

    std::cout << std::endl << std::endl;
    BinarySearchTree<int, std::string> bst2{
        {5, "five"},
        {3, "three"},
        {7, "seven"},
        {2, "two"},
        {4, "four"},
    };
    std::cout << "Inorder traversal after list initialization: " << std::endl;
    bst2.inorder();

    BinarySearchTree<char, int> bst3(bst);

}
