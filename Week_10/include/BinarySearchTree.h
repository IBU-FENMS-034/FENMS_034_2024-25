//
// Created by aldin on 12/02/2025.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Node.h"
#include <initializer_list>

template<typename Key, typename Value>
class BinarySearchTree {
private:
    Node<Key, Value>* root{};
    Node<Key, Value>* put(Node<Key, Value>* x, Key key, Value value);
    Node<Key, Value>* find_min(Node<Key, Value>* x);
    Node<Key, Value>* find_max(Node<Key, Value>* x);
    int rank(Node<Key, Value>* x, Key key);
    Node<Key, Value>* delete_min(Node<Key, Value>* x);
    Node<Key, Value>* delete_any(Node<Key, Value>* x, Key key);
    void inorder(Node<Key, Value>* x);
    void preorder(Node<Key, Value>* x);
    void postorder(Node<Key, Value>* x);
    int size(Node<Key, Value>* x) const;
    void delete_tree(Node<Key, Value>* x);
    Node<Key, Value>* copy_tree(Node<Key, Value> *x);
public:
    BinarySearchTree() = default;
    BinarySearchTree(std::initializer_list<std::pair<Key, Value>> list);
    BinarySearchTree(const BinarySearchTree<Key, Value>& src);
    BinarySearchTree<Key, Value>& operator=(const BinarySearchTree<Key, Value>& src);
    BinarySearchTree(BinarySearchTree<Key, Value>&& src) noexcept;
    BinarySearchTree<Key, Value>& operator=(BinarySearchTree<Key, Value>&& src) noexcept;
    ~BinarySearchTree();

    Value get(Key key);
    void put(Key key, Value value);
    Key find_min();
    Key find_max();
    int rank(Key key);
    void delete_min();
    void delete_any(Key key);
    int size() const;
    void inorder();
    void preorder();
    void postorder();
};

#include "BinarySearchTree.tpp"

#endif //BINARYSEARCHTREE_H
