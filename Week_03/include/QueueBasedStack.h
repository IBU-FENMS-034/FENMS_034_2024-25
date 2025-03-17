#ifndef QUEUEBASEDSTACK_H
#define QUEUEBASEDSTACK_H

#include "Queue.h"

template<typename Data>
class QueueBasedStack {
private:
    Queue<Data> q1;
    Queue<Data> q2;

public:
    QueueBasedStack();

    void push(const Data& data);
    Data pop();
    Data peek() const;
    int size() const;
    bool is_empty() const;
};

#include "QueueBasedStack.tpp"

#endif // QUEUEBASEDSTACK_H
