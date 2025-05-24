//
// Created by aldin on 13/02/2025.
//

#ifndef NODE_H
#define NODE_H

template<typename Key, typename Value>
struct Node {
    Key key;
    Value value;
    int size{1};
    Node<Key, Value>* left{};
    Node<Key, Value>* right{};
    bool color;

    Node(Key k, Value v, bool color) {
        this->key = k;
        this->value = v;
        this->color = color;
    }
};

#endif //NODE_H
