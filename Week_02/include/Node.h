//
// Created by aldin on 10/03/2025.
//

#ifndef NODE_H
#define NODE_H

template<typename Data>
struct Node {
    Data data;
    Node *next{};

    Node() = default;
    explicit Node(Data data) : data(data) {}
};

#endif //NODE_H
