//
// Created by aldin on 16/03/2025.
//

#include <iostream>
#include "../include/Stack.h"
#include "../include/Queue.h"
#include "../include/QueueBasedStack.h"
void stack_demo();
void queue_demo();
void queue_based_stack_demo();
int main() {

    queue_based_stack_demo();
    //stack_demo();
    //std::cout << std::endl;
    //queue_demo();
    return 0;

}

void stack_demo() {
    std::cout << "Stack demo:" << std::endl;
    Stack<int> stack;

    stack.push(2);
    stack.push(8);
    stack.push(5);

    std::cout << "Top of stack: " << stack.peek() << std::endl;
    std::cout << "Removing: " << stack.pop() << std::endl;
    std::cout << "Removing: " << stack.pop() << std::endl;
    std::cout << "Removing: " << stack.pop() << std::endl;

    stack.push(10);
    std::cout << "Top of stack: " << stack.peek() << std::endl;
    std::cout << "Stack size: " << stack.size() << std::endl;

    std::cout << std::endl;

    Stack<char> stack2{'s', 't', 'a', 'c', 'k'};
    std::cout << "List-initialized stack:" << std::endl;
    std::cout << "- Top of stack2: " << stack2.peek() << std::endl;
    std::cout << "- Removing: " << stack2.pop() << std::endl;
    std::cout << "- Removing: " << stack2.pop() << std::endl;
    std::cout << "- Removing: " << stack2.pop() << std::endl;
    std::cout << "- Removing: " << stack2.pop() << std::endl;
    std::cout << "- Removing: " << stack2.pop() << std::endl;
}

void queue_demo() {
    std::cout << "Queue demo:" << std::endl;
    Queue<int> queue;

    queue.enqueue(2);
    queue.enqueue(8);
    queue.enqueue(5);

    std::cout << "Head of queue: " << queue.peek() << std::endl;
    std::cout << "Removing: " << queue.dequeue() << std::endl;
    std::cout << "Removing: " << queue.dequeue() << std::endl;
    std::cout << "Removing: " << queue.dequeue() << std::endl;

    queue.enqueue(10);
    std::cout << "Head of queue: " << queue.peek() << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    std::cout << std::endl;

    Queue<char> queue2{'q', 'u', 'e', 'u', 'e'};
    std::cout << "List-initialized queue:" << std::endl;
    std::cout << "- Head of queue2: " << queue2.peek() << std::endl;
    std::cout << "- Removing: " << queue2.dequeue() << std::endl;
    std::cout << "- Removing: " << queue2.dequeue() << std::endl;
    std::cout << "- Removing: " << queue2.dequeue() << std::endl;
    std::cout << "- Removing: " << queue2.dequeue() << std::endl;
    std::cout << "- Removing: " << queue2.dequeue() << std::endl;
}
void queue_based_stack_demo() {
    std::cout << "Queue-Based Stack Demo:" << std::endl;
    QueueBasedStack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << std::endl;
    std::cout << "Popping: " << stack.pop() << std::endl;
    std::cout << "Popping: " << stack.pop() << std::endl;

    stack.push(40);
    std::cout << "Top element after pushing 40: " << stack.peek() << std::endl;

    std::cout << "Stack size: " << stack.size() << std::endl;
    std::cout << "Is stack empty? " << (stack.is_empty() ? "Yes" : "No") << std::endl;

    std::cout << std::endl;

    QueueBasedStack<char> stack2;
    stack2.push('A');
    stack2.push('B');
    stack2.push('C');

    std::cout << "Top of stack2: " << stack2.peek() << std::endl;
    std::cout << "Removing: " << stack2.pop() << std::endl;
    std::cout << "Removing: " << stack2.pop() << std::endl;
    std::cout << "Removing: " << stack2.pop() << std::endl;

    std::cout << "Is stack2 empty? " << (stack2.is_empty() ? "Yes" : "No") << std::endl;

}