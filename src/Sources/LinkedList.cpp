#include "LinkedList.hpp"

void Construct(ForwardList& list) {
	list.Head = nullptr;
}

void PopFront(ForwardList& list) {
	ForwardList::Node* newHead = list.Head->Next;
	delete list.Head;
	list.Head = newHead;
}

void Destruct(ForwardList& list) {
	while (list.Head != nullptr) {
		PopFront(list);
	}
}

void PushFront(ForwardList& list, int value) {
	ForwardList::Node* newNode = new ForwardList::Node{ list.Head , value };
	list.Head = newNode;
}

void RemoveAfter(ForwardList::Node* node) {
	if (node == nullptr || node->Next == nullptr) {
		return;
	}
	else {
		ForwardList::Node* new_node = node->Next->Next;
		delete node->Next;
		node->Next = new_node;
	}
}

size_t Size(const ForwardList& list) {
	ForwardList::Node* node = list.Head;
	size_t k = 0;
	while (node != nullptr) {
		++k;
		node = node->Next;
	}
	return k;
}

ForwardList::Node* InsertAfter(ForwardList::Node* node, int value) {
	ForwardList::Node* newNode = new ForwardList::Node{ node->Next, value };
	node->Next = newNode;
	return node;
}

void PrintList(const ForwardList& list) {
	ForwardList::Node* node = list.Head;
	while (node != nullptr) {
		std::cout << node->Data << " ";
		node = node->Next;
	}
	std::cout << std::endl;
}

void Reverse(ForwardList& list) {
	ForwardList::Node* curr = list.Head;
	ForwardList::Node* prev = nullptr;
	ForwardList::Node* next = nullptr;
	while (curr != nullptr) {
		std::swap(curr, curr->Next);
		curr = curr->Next;
		/*next = curr->Next;
		curr->Next = prev;
		prev = curr;
		curr = next;*/
	}
	list.Head = curr;
	delete curr;
	delete next;
}
