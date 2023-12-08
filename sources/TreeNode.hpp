#ifndef INCLUDE_TREENODE_HPP_
#define INCLUDE_TREENODE_HPP_

#include <iostream>

struct TreeNode {
	struct Node {
		int value;
		Node* left;
		Node* right;
	};
	Node* root;
};
void construct(TreeNode& treeNode);
void destruct(TreeNode::Node* leaf);
void insert(int value, TreeNode& treeNode);
void Add_Node(TreeNode::Node* leaf, int value);
void printTreeNode(TreeNode& treeNode);
TreeNode::Node* Search(TreeNode& treenode, int value);
#endif // INCLUDE_TREENODE_HPP_
