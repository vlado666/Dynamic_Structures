#ifndef INCLUDE_LINKEDLIST_HPP_
#define INCLUDE_LINKEDLIST_HPP_

#include <iostream>
#include <algorithm>

struct ForwardList {
	struct Node {
		Node* Next;
		int Data;
	};

	Node* Head;
};

void Construct(ForwardList& list);
void PopFront(ForwardList& list);
void Destruct(ForwardList& list);
void PushFront(ForwardList& list, int value);
void RemoveAfter(ForwardList::Node* node);
size_t Size(const ForwardList& list);
ForwardList::Node* InsertAfter(ForwardList::Node* node, int value);
void PrintList(const ForwardList& list);
void Reverse(ForwardList& list);

#endif // INCLUDE_LINKEDLIST_HPP_