//
// Created by aldin on 10/03/2025.
//

#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template<typename Data>
struct DoubleNode {
    Data data;
    DoubleNode *next{};
    DoubleNode *prev{};

    DoubleNode() = default;
    explicit DoubleNode(Data data) : data(data) {}
};

#endif //DOUBLENODE_H
