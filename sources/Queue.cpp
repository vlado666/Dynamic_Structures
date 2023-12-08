#include "Queue.hpp"

void Construct(Queue& queue) {
    queue.Head = nullptr;
    queue.Tail = nullptr;
}

void Destruct(Queue& queue) {
    while (queue.Head != nullptr) {
        Queue::Node* newHead = queue.Head->Next;
        delete queue.Head;
        queue.Head = newHead;
    }
    queue.Tail = nullptr;
}

void Push(Queue& queue, int value) {
    Queue::Node* newNode = new Queue::Node{ nullptr, value };
    if (queue.Head == nullptr) {
        queue.Head = queue.Tail = newNode;
    }
    else {
        queue.Tail->Next = newNode;
        queue.Tail = newNode;
    }
}

bool Empty(const Queue& queue) {
    return queue.Head == nullptr;
}

int Pop(Queue& queue) {
    if (queue.Head != nullptr) {
        Queue::Node* temp_node = queue.Head;
        int result = temp_node->Data;
        queue.Head = queue.Head->Next;
        delete temp_node;
        return result;
    }
    return 0;
}

size_t size(const Queue& queue) {
    size_t k = 0;
    Queue::Node* node = queue.Head;
    while (node != nullptr) {
        ++k;
        node = node->Next;
    }
    delete node;
    return k;
}
void PrintQueue(const Queue& queue) {
    std::cout << "Head -> ";
    Queue::Node* node = queue.Head;
    while (node != nullptr) {
        std::cout << node->Data << " ";
        node = node->Next;
    }
    delete node;
    std::cout << std::endl;
}
