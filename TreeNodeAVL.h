#pragma once
#include <iostream>
using namespace std;
#include "mQueue.h"
template<class type>
class AVLNode {
private:
	int key;
	type data;
	AVLNode<type> * parent;
	AVLNode<type> * left;
	AVLNode<type> * right;
	template<class U> friend class AvlTree;
	void visit() {
		cout << data << " , " << key << endl;;
	}
public:
	AVLNode(const type & data, int key) : parent(NULL), left(NULL), right(NULL) {
		this->data = data;
	}

	AVLNode(const type & data) : key(0), parent(NULL), left(NULL), right(NULL) {
		this->data = data;
	}

	~AVLNode() {
	}
	
	type getData() const {
		return this->data;
	}

	int getKey() const {
		return this->key;
	}

	AVLNode<type> * getParent() const {
		return this->parent;
	}

	void preorder() {
		this->visit();
		if (left != NULL) left->preorder();
		if (right != NULL) right->preorder();
	}

	void inorder() {
		if (left != NULL) left->inorder();
		this->visit();
		if (right != NULL) right->inorder();
	}

	void postorder() {
		if (left != NULL) left->postorder();
		if (right != NULL) right->postorder();
		this->visit();
	}

	void levelorder() {
		if (this == NULL) return;
		mQueue< AVLNode<type>* > Q;
		Q.enqueue(this);
		while (!Q.isEmpty()) {
			AVLNode<type> *n = Q.dequeue();
			n->visit();
			if (n->left != NULL) Q.enqueue(n->left);
			if (n->right != NULL) Q.enqueue(n->right);
		}
	}
};
