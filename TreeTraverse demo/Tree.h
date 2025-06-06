#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
using namespace std;
template <class T> class Tree;
template <class T> class TreeNode;

template <class T> class TreeNode {
	friend class Tree<T>;
private:
	TreeNode<T> *LeftChild;
	T  data;
	TreeNode<T> *RightChild;
};

template <class T> class Tree {
public:
	Tree(TreeNode<T> data, TreeNode<T>* left, TreeNode<T>* right) {
		root = &data;
		root->LeftChild = left;
		root->RightChild = right;
	};

	Tree() { root = NULL; };
	~Tree() {};
	bool isempty() { return(root == NULL); };
	void Insert(T);
	void Inorder() {
		Inorder(root);
		cout << endl;
	};    // Driver
	void Inorder(TreeNode<T>* CurrentNode) {
		if (CurrentNode != NULL) {
			Inorder(CurrentNode->LeftChild);  // Visit LeftChild subtree
			cout << CurrentNode->data << " ";   // Print data
			Inorder(CurrentNode->RightChild); // Visit RightChild subtree
		}
	}; // Workhorse
	void Preorder() {
		Preorder(root);
		cout << endl;
	};
	void Preorder(TreeNode<T>*);
	void Postorder() {
		cout << "do postorder by yourself\n";
	};
	void Postorder(TreeNode<T>*);
	void Levelorder();
private:
	TreeNode<T> *root;
};

//Function to visit nodes in Preorder
template <class T>
void Tree<T>::Preorder(TreeNode <T>* CurrentNode) {
	cout << "do preorder by yourself\n";
};

//Function to visit nodes in Postorder
template <class T>
void Tree<T>::Postorder(TreeNode<T>* CurrentNode) {
	cout << "do it by yourself\n";
};
// Insert the item into the tree according to its priority, i.e., A<C<E etc.
// That is the so-called binary search tree
template <class T>
void Tree<T>::Insert(T item) {
	cout << "do BST insert by yourself\n";
};

template <class T>
void Tree<T>::Levelorder() {
	cout << "do levelorder by yourself\n";
};

#endif