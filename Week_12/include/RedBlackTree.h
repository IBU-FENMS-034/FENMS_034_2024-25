//
// Created by aldin on 13/02/2025.
//

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <initializer_list>
#include <utility>

#include "Node.h"

#define RED true
#define BLACK false

template<typename Key, typename Value>
class RedBlackTree {
private:
    Node<Key, Value>* root{};
    Node<Key, Value>* put(Node<Key, Value>* x, Key key, Value value);
    int size(Node<Key, Value>* x) const;
    Node<Key, Value>* rotate_right(Node<Key, Value>* h);
    Node<Key, Value>* rotate_left(Node<Key, Value>* h);
    void flip_colors(Node<Key, Value>* h);
    bool is_red(Node<Key, Value>* x) const;
    void delete_tree(Node<Key, Value>* x);
    Node<Key, Value>* copy_tree(Node<Key, Value> *x);
    Node<Key, Value>* find_min(Node<Key, Value>* x);
    // Deletion
    Node<Key, Value>* fix_up(Node<Key, Value>* h);
    Node<Key, Value>* delete_min(Node<Key, Value>* h);
    Node<Key, Value>* delete_any(Node<Key, Value>* h, Key key);
    Node<Key, Value>* move_red_left(Node<Key, Value>* h);
    Node<Key, Value>* move_red_right(Node<Key, Value>* h);
public:
    RedBlackTree() = default;
    RedBlackTree(std::initializer_list<std::pair<Key, Value>> list);
    RedBlackTree(const RedBlackTree<Key, Value>& src);
    RedBlackTree<Key, Value>& operator=(const RedBlackTree<Key, Value>& src);
    RedBlackTree(RedBlackTree<Key, Value>&& src) noexcept;
    RedBlackTree<Key, Value>& operator=(RedBlackTree<Key, Value>&& src) noexcept;
    ~RedBlackTree();

    Value get(Key key);
    void put(Key key, Value value);
    int size() const;
    Key find_min();
    // Deletion
    void delete_min();
    void delete_any(Key key);
};

#include "RedBlackTree.tpp"

#endif //REDBLACKTREE_H
