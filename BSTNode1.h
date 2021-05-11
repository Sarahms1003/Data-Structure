#pragma once
#include"Enemies/Enemy.h"
#include<iostream>
using namespace std;

template <typename T>
class BSTNode
{
public:
	struct node
	{
		T value;
		struct node* right;
		struct node* left;
		Enemy* pE;
	}
	struct node* root;
	int treeSize;
	BSTNode();
	~BSTNode();
	bool add(const T& val, Enemy* pE, node* n);
	bool Search(struct node* node, T val);
	void printPreOrder(struct node* node);
	Enemy* printInOrder(node* t);
	void printPostOrder(struct node* node);
	void deleteTree(node* t);
	bool deleteNode(const T& root, Enemy* pE));
	const T* toArray(int& count);	//returns array of T (array of items)

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
bool BSTNode<T>::add(const T& val, Enemy* pE, node* n )  //Val is the frosted-Arrival Time
{

	if (*node == NULL) {
		struct node* tmp = new struct node;
		tmp->value = val;
		tmp->left = NULL;
		tmp->right = NULL;
		*node = tmp;

		this->treeSize++;
	}
	else {
		if (val > (*node)->value) 
		{
			add(&(*node)->right, val);
		}
		else 
		{
			add(&(*node)->left, val);
		}
	}
}

template<typename T>
Enemy* BSTNode<T>::printInOrder(struct node* node) 
{
	//node->pE
	if (node != NULL) 
	{
		printInOrder(node->left);
		std::cout << node->value;
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
void BSTNode<T>::printPostOrder(node* t) 
{
	if (node != NULL) 
	{
		printInOrder(node->left);
		printInOrder(node->right);
		std::cout << node->value << ", ";
	}
}


template<typename T>
void BSTNode<T>::deleteTree(node* t)
{
	if (node != NULL) {
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template<typename T>
bool BSTNode<T>::Search(struct node* node, T val) 
{
	if (node == NULL) 
	{
		return false;
	}
	else {
		if (val == node->value) 
		{
			return true;
		}

		if (val > node->value) 
		{
			return lookup(node->right, val);
		}
		else
		{
			return lookup(node->left, val);
		}
	}

}
template<typename T>
 bool BSTNode<T>::deleteNode(const T& root, Enemy* pE)
{
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted is smaller than the root's key, then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than the root's key, then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node to be deleted
	else {
		// node with only one child or no child
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest in the right subtree)
		struct node* temp = minValueNode(root->right);

		// Copy the inorder
		// successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

 template <typename T>
 const T* BSTNode<T>::toArray(int& count)
 {
	 count = 0;
	 //counting the no. of items in the tree
	 node* root;
		 if (root == NULL)
			 return 0;
		 if (root->left != NULL)
		 {
			 count++;
		 }
		 if (root->right != NULL)
		 {
			 count++;
		 }
	 

	 T* Arr = new T[count];
	 BSTNode oB;
	 for (int i = 0; i < count; i++)
	 {
		 arr[i] = oB.printInOrder(node * t);
	 }
	 return Arr;
	 

 }

