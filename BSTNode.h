#pragma once
#include<iostream>
using namespace std;

template <typename T>
class BSTNode
{
	struct node
	{
		T value;
		struct node* right;
		struct node* left;
	}
	struct node* root;
	int treeSize;
	BSTNode();
	~BSTNode();
	void add(struct node** node, T val);
	bool Search(struct node* node, T val);
	void printPreOrder(struct node* node);
	void printInOrder(struct node* node);
	void printPostOrder(struct node* node);
	void deleteTree(struct node* node);
};
template<typename T>
BSTNode<T>::BSTNode()
{
	this->root = NULL;
	this->treeSize = 0;
}

template <class T>
BSTNode<T>::~BSTNode()
{
	deleteTree(this->root);
}

template<typename T>
void BSTNode<T>::add(struct node** node, T val) {

	if (*node == NULL) {
		struct node* tmp = new struct node;
		tmp->value = val;
		tmp->left = NULL;
		tmp->right = NULL;
		*node = tmp;

		this->treeSize++;
	}
	else {
		if (val > (*node)->value) {
			add(&(*node)->right, val);
		}
		else {
			add(&(*node)->left, val);
		}
	}
}

template<typename T>
void BSTNode<T>::printInOrder(struct node* node)
{
	if (node != NULL) {
		printInOrder(node->left);
		std::cout << node->value << ", ";
		printInOrder(node->right);
	}
}

template<typename T>
void BSTNode<T>::printPreOrder(struct node* node)
{
	if (node != NULL) {
		std::cout << node->value << ", ";
		printInOrder(node->left);
		printInOrder(node->right);
	}
}

template<typename T>
void BSTNode<T>::printPostOrder(struct node* node)
{
	if (node != NULL) {
		printInOrder(node->left);
		printInOrder(node->right);
		std::cout << node->value << ", ";
	}
}


template<typename T>
void BSTNode<T>::deleteTree(struct node* node)
{
	if (node != NULL) {
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template<typename T>
bool BSTNode<T>::Search(struct node* node, T val) {
	if (node == NULL) {
		return false;
	}
	else {
		if (val == node->value) {
			return true;
		}

		if (val > node->value) {
			return lookup(node->right, val);
		}
		else {
			return lookup(node->left, val);
		}
	}

}