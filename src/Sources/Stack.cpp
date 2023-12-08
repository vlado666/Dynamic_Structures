#include "Stack.hpp"

void Construct(Stack& stack) {
	stack.Top = nullptr;
}

void Destruct(Stack& stack) {
	while (stack.Top != nullptr) {
		Pop(stack);
	}
}

void Push(Stack& stack, int value) {
	Stack::Node* node = new Stack::Node{ stack.Top, value };
	stack.Top = node;
}

int Pop(Stack& stack) {
	int val = stack.Top->Data;
	Stack::Node* newTop = stack.Top->Next;
	delete stack.Top;
	stack.Top = newTop;
	return val;
}

bool Empty(const Stack& stack) {
	return stack.Top == nullptr;
}