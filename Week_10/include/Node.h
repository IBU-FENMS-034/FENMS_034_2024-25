//
// Created by aldin on 12/02/2025.
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

    Node(Key k, Value v) {
        this->key = k;
        this->value = v;
    }
};

#endif //NODE_H
