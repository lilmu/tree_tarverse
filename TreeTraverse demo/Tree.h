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

		~Tree() {
			TreeNode<T>* CurrrentNode = root;
			queue <TreeNode<T>> q;
			while (CurrentNode) {
				if (CurrentNode->LeftChild) q.push(CurrentNode->LeftChild);
				if (CurrentNode->RightChild) q.push(CurrentNode->RightChild);
				delete CurrentNode;
				CurrentNode = q.front;
				q.pop;
			}
			cout << "Tree Destructor Called"
		};

		bool isempty() { return(root == NULL); };

		// insert method
		void Insert(T x) {
			TreeNode<T>* p = root;
			TreeNode<T>* q = NULL;
			while (p) {
				q = p;
				if (x == p->data) return;
				if (x < p->data) p = p->LeftChild;
				else p = p->RightChild;
			}
			p = new TreeNode<T>;
			p->LeftChild = NULL;
			p->RightChild = NULL;
			p->data = x;
			if (!root) {
				root = p;
			}
			else if (p->data > q->data) {
				q->RightChild = p;
			}
			else {
				q->LeftChild = p;
			}
			return;
		};

		// inorder expression
		void Inorder() {
			Inorder(root);
			cout << endl;
		};
		void Inorder(TreeNode<T>* CurrentNode) {
			if (CurrentNode != NULL) {
				Inorder(CurrentNode->LeftChild);  // Visit LeftChild subtree
				cout << CurrentNode->data << " ";   // Print data
				Inorder(CurrentNode->RightChild); // Visit RightChild subtree
			}
		}; 

		// preorder expression
		void Preorder() {
			Preorder(root);
			cout << endl;
		};
		void Preorder(TreeNode<T>* CurrentNode) {
			if (CurrentNode != NULL) {
				cout << CurrentNode->data << " ";   // Print data
				Inorder(CurrentNode->LeftChild);  // Visit LeftChild subtree
				Inorder(CurrentNode->RightChild); // Visit RightChild subtree
			}
		};

		// postorder expression
		void Postorder() {
			Postorder(root);
			cout << endl;
		};
		void Postorder(TreeNode<T>* CurrentNode) {
			if (CurrentNode != NULL) {
				Inorder(CurrentNode->LeftChild);  // Visit LeftChild subtree
				Inorder(CurrentNode->RightChild); // Visit RightChild subtree
				cout << CurrentNode->data << " ";   // Print data
			}
		};

		// levelorder expression
		void Levelorder() {
			queue<TreeNode<T>> q;
			TreeNode<T>* CurrentNode = root;
			while (CurrentNode) {
				cout << CurrentNode->data << endl;
				if (CurrentNode->LeftChild) q.push(CurrentNode->LeftChild);
				if (CurrentNode->RightChild) q.push(CurrentNode->RightChild);
				CurrentNode = q.front;
				q.pop;
			}
		};

	private:
		TreeNode<T> *root;
};

////Function to visit nodes in Preorder
//template <class T>
//void Tree<T>::Preorder(TreeNode <T>* CurrentNode) {
//	cout << "do preorder by yourself\n";
//};
//
////Function to visit nodes in Postorder
//template <class T>
//void Tree<T>::Postorder(TreeNode<T>* CurrentNode) {
//	cout << "do it by yourself\n";
//};
//// Insert the item into the tree according to its priority, i.e., A<C<E etc.
//// That is the so-called binary search tree
//template <class T>
//void Tree<T>::Insert(T item) {
//	cout << "do BST insert by yourself\n";
//};
//
//template <class T>
//void Tree<T>::Levelorder() {
//	cout << "do levelorder by yourself\n";
//};

#endif