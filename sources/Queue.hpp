#ifndef INCLUDE_QUEUE_HPP_
#define INCLUDE_QUEUE_HPP_

#include <iostream>

struct Queue {
    struct Node {
        Node* Next = nullptr;
        int Data = 0;
    };

    Node* Head = nullptr;

    Node* Tail = nullptr;
};

void Construct(Queue& queue);
void Destruct(Queue& queue);
void Push(Queue& queue, int value);
int Pop(Queue& queue);
bool Empty(const Queue& queue);
void PrintQueue(const Queue& queue);
size_t size(const Queue& queue);

#endif  // INCLUDE_QUEUE_HPP_