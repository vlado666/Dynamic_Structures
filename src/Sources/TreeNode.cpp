#include "treeNode.hpp"

void Add_Node(TreeNode::Node* leaf, int value) {
	if (value < leaf->value) {
		if (leaf->left != nullptr) {
			Add_Node(leaf->left, value);
		}
		else {
			leaf->left = new TreeNode::Node;
			leaf->left->value = value;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else {
		if (leaf->right != nullptr) {
			Add_Node(leaf->right, value);
		}
		else {
			leaf->right = new TreeNode::Node;
			leaf->right->value = value;
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
		}
	}
}

void construct(TreeNode& treeNode) {
	treeNode.root = nullptr;
}

void destruct(TreeNode::Node* leaf) {
	if (leaf != nullptr) {
		destruct(leaf->left);
		destruct(leaf->right);
		delete leaf;
	}
}

void insert(int value, TreeNode& treeNode) {
	if (treeNode.root != nullptr) {
		Add_Node(treeNode.root, value);
	}
	else {
		treeNode.root = new TreeNode::Node;
		treeNode.root->left = nullptr;
		treeNode.root->right = nullptr;
		treeNode.root->value = value;
	}
}

void printTreeNode(TreeNode::Node* leaf) {
	if (leaf != nullptr) {
		printTreeNode(leaf->left);
		std::cout << leaf->value << " ";
		printTreeNode(leaf->right);

	}
}

void printTreeNode(TreeNode& treeNode) {
	printTreeNode(treeNode.root);
	std::cout << std::endl;
}

TreeNode::Node* Search(TreeNode::Node* leaf, int value) {
	if (leaf == nullptr) {
		return nullptr;
	}
	else {
		if (leaf->value == value) {
			return leaf;
		}
		else {
			if (value < leaf->value) {
				return Search(leaf->left, value);
			}
			else {
				return Search(leaf->right, value);
			}
		}
	}
}
TreeNode::Node* Search(TreeNode& treenode, int value) {
	return Search(treenode.root, value);
}
