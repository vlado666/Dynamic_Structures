#include <iostream>
#include "LinkedList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "treeNode.hpp"

int main() {
	ForwardList list;
	Construct(list);
	PushFront(list, 0);
	PushFront(list, 1);
	PushFront(list, 2);
	PushFront(list, 3);
	PrintList(list);
	RemoveAfter(list.Head);
	InsertAfter(list.Head, 2);
	auto* newNode = InsertAfter(list.Head->Next, -1);
	PrintList(list);

	InsertAfter(list.Head->Next, 99999);
	PrintList(list);
	Reverse(list);
	PrintList(list);
	//--------------------------
	/*int a;
	Queue queue;
	Construct(queue);
	Push(queue, 0);
	std::cout << Empty(queue) << std::endl;
	PrintQueue(queue);
	a = Pop(queue);
	std::cout << Empty(queue) << std::endl;*/
	//-------------------------
	/*TreeNode treenode;
	construct(treenode);
	insert(10, treenode);
	insert(102, treenode);
	insert(101, treenode);
	destruct(treenode.root);
	printTreeNode(treenode);*/
	return 0;
}