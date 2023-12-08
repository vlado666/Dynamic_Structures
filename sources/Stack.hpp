#include <iostream>

struct Stack {
    struct Node {
        Node* Next;
        int Data;
    };
    Node* Top;
};

void Construct(Stack& stack);
void Destruct(Stack& stack);
void Push(Stack& stack, int value);
int Pop(Stack& stack);
bool Empty(const Stack& stack);