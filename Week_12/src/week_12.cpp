//
// Created by aldin on 13/02/2025.
//

#include <iostream>

#include "../include/RedBlackTree.h"

int main() {
    RedBlackTree<char, int> rbt;

    rbt.put('T', 1);
    rbt.put('E', 2);
    rbt.put('X', 3);
    rbt.put('A', 4);
    rbt.put('R', 5);
    rbt.put('C', 6);
    rbt.put('H', 7);
    rbt.put('M', 8);

    std::cout << "Key R holds value: " << rbt.get('R') << std::endl;
    std::cout << "Key M holds value: " << rbt.get('M') << std::endl;
    std::cout << "Key X holds value: " << rbt.get('X') << std::endl;

    std::cout << "Min key before min deletion: " << rbt.find_min() << std::endl;
    rbt.delete_min();
    std::cout << "Min key after min deletion: " << rbt.find_min() << std::endl;
    rbt.delete_min();
    std::cout << "Min key after another deletion: " << rbt.find_min() << std::endl;
    std::cout << "Size of tree after 2 min deletions: " << rbt.size() << std::endl;

    rbt.delete_any('H');
    std::cout << "Key H holds value: " << rbt.get('H') << std::endl;
    std::cout << "Size of tree after deletion: " << rbt.size() << std::endl;
}
