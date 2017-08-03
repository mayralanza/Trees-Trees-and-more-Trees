/********************************************
* Project 3 - Trees. Trees, and more Trees  *
* Team 22: Mayra Lanza                      *
*          Giovany Gonzalez                 *
*********************************************/
#include "TreeNodeAVL.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
template<class type>
class AvlTree {
protected:
	AVLNode<type> * root;
	int size;
public:
	AvlTree() :root(NULL), size(0) {}

	~AvlTree() { if (this->size != 0) this->clear(root); }

	AVLNode<type>* getRoot() const {
		if (this->isEmpty()) {
			throw underflow_error("The Tree is empty. Root node does not exist.");
		}
		return root;
	}

	int getSize() const {
		return size;
	}

	bool isEmpty() const {
		return size == 0;
	}

	int leaves(AVLNode<type>* ptr) {
		if (ptr == NULL)
			return 0;
		if (ptr->left == NULL && ptr->right == NULL)
			return 1;
		else
			return leaves(ptr->right) + leaves(ptr->left);
	}
	
	int getDepth(AVLNode<type>* ptr) {
		int counter = 0;
		while (ptr->getParent() != NULL) {
			counter++;
			ptr = ptr->getParent();
		}
		return counter;
	}

	int siblibgs(AVLNode<type>* ptr) {
		if (ptr->parent == NULL) {
			return -1;
		}
		ptr = ptr->parent;
		if (ptr->right == NULL || ptr->left == NULL) {
			return 0;
		}
		else
			return 1;
	}

	void inorder()
	{
		if (this->isEmpty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be displayed.");
		}
		this->getRoot()->inorder();
	}

	void levelorder()
	{
		if (this->isEmpty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be displayed.");
		}
		this->getRoot()->levelorder();
	}

	void preorder()
	{
		if (this->isEmpty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be displayed.");
		}
		this->getRoot()->preorder();
	}

	void postorder()
	{
		if (this->isEmpty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be displayed.");
		}
		this->getRoot()->postorder();
	}

	AVLNode<type>* rotateLeft(AVLNode<type> *a) {
		AVLNode<type> *b = a->right;
		b->parent = a->parent;
		a->right = b->left;

		if (a->right != NULL)
			a->right->parent = a;

		b->left = a;
		a->parent = b;

		if (b->parent != NULL) {
			if (b->parent->right == a) {
				b->parent->right = b;
			}
			else {  //---->>New Root parent = NULL
				b->parent->left = b;
			}
		}
		else {
			this->root = b;
		}
	return b;
	}

	AVLNode<type>* rotateRight(AVLNode<type> *a) {
		AVLNode<type> *b = a->left;
		b->parent = a->parent;
		a->left = b->right;

		if (a->left != NULL)
			a->left->parent = a;

		b->right = a;
		a->parent = b;

		if (b->parent != NULL) {
			if (b->parent->right == a) {
				b->parent->right = b;
			}
			else {
				b->parent->left = b;
				this->root = b;
			}
		}
		else {
			this->root = b;
		}
		return b;
	}


	AVLNode<type>* leftrightrotate(AVLNode<type> *n) {
		n->left = rotateLeft(n->left);
		return rotateRight(n);
	}

	AVLNode<type>* rightleftrotate(AVLNode<type> *n) {
		n->right = rotateRight(n->right);
		return rotateLeft(n);
	}

	void rebalance(AVLNode<type> *n) {
		if (this->getSize() <= 1) {
			return;
		}
		else {
			bool rotate = false;
			while (n->parent != NULL && !rotate) {
				n = n->getParent();
				//------------------->checking balance
				int L_subtree = height(n->left);
				int R_subtree = height(n->right);
				int balancefactor = L_subtree - R_subtree;
				if (balancefactor <= -2 || balancefactor >= 2) {
					rotate = true;
				}
			}
			if (rotate) {
				AVLNode<type>* ptr;
				
				if (n->left != NULL && n->left->left != NULL) { //L.L. --->right rotation
					ptr = rotateRight(n);
				}
				if (n->left != NULL && n->left->right != NULL) { //L.R. ---> Left & right rotation
					ptr = leftrightrotate(n);
				}
				if (n->right != NULL && n->right->right != NULL) { //R.R ---> Left rotation
					ptr = rotateLeft(n);
				}
				if (n->right != NULL && n->right->left != NULL) { //R.L ---> Left rotation
					ptr = rightleftrotate(n);
				}
				rebalance(ptr);
			}
		}
	}

	int height() { //Height of the tree
		int left = height(this->root->left);
		int right = height(this->root->right);
		return 1 + max(left, right);
	}

	int height(AVLNode<type> *n) {
		if (n == NULL)
			return -1;
		return 1 + max(height(n->left), height(n->right));
	}

	//MUTATORS
	void BuildTree() {
		string line;
		ifstream myfile("tree2.txt");
		if (myfile.is_open())
		{
			while (myfile.good())
			{
				int parent_key;
				string data;
				myfile >> parent_key;
				if (myfile.eof()) {
					break;
				}
				myfile >> data;
				insert(data, parent_key);
			}
			myfile.close();
		}
		else
			cout << "Unable to open file";

	};

	void insert(const type & data, int key) {
		if (root == NULL) {
			AVLNode<type> *n = new AVLNode<type>(data);
			n->key = key;
			root = n;
			size++;
			return ;
		}
		else {
			AVLNode<type> *n = new AVLNode<type>(data);
			n->key = key;
			size++;
			AVLNode<type> *ptr = root;
			AVLNode<type> *prev = NULL;
			int ind = 0;
			while (ptr != NULL) {
				if (key <= ptr->key) {
					prev = ptr;
					ptr = ptr->left;
					ind = 0;
				}
				else if (key > ptr->key) {
					prev = ptr;
					ptr = ptr->right;
					ind = 1;
				}
			}
			n->parent = prev;
			if (ind == 0) prev->left = n;
			else prev->right = n;
			rebalance(n);
		}
	}

	AVLNode<type>* find(const int &key) {
		if (this->isEmpty()) {   //check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be found.");
		}
		else {
			AVLNode<type> * node = this->root;
			while (node != NULL) {
				if (key < node->key) node = node->left;
				else if (key > node->key) node = node->right;
				else return node;
			}
		}
		return NULL;
	}

	void clear(AVLNode<type>* del){
		if (del != NULL) {
			clear(del->left);
			clear(del->right);
			delete del;
			this->root = NULL;
			this->size = 0;
		}
	}

	void del(const int &key) {
		if (this->isEmpty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be deleted.");
		}
		AVLNode<type>* node = find(key);
		AVLNode<type>* d_node = node; //---->temp variable
		if (node->left == NULL && node->right == NULL) { //---->Tree node has no children
			AVLNode<type>* p = node->getParent();
			// reset pointer to null
			if (node->key == p->left->key)
				p->left = NULL;
			else
				p->right = NULL;

			delete node;
			rebalance(p);
		}
		else if (node->left == NULL || node->right == NULL) { //---->Tree node has one child
			AVLNode<type>* n = node->left;
			// take right node left is null
			if (n == NULL)
				n = node->right;

			AVLNode<type>* p = node->getParent();
			if (p == NULL) { //------> Node is the root
				delete node;
				this->root = n;
				this->size--;
				return;
			}
			// move pointer
			if (node->key == p->left->key)
				p->left = n;
			else
				p->right = n;

			node->left = NULL;
			node->right = NULL;
			delete node;
			rebalance(p);

		}
		else
			if (node->left != NULL && node->right != NULL) { //--->Tree node has two children

															 // get right node
				AVLNode<type>* r = node->right;
				// get first left node
				AVLNode<type>* l = r->left;
				AVLNode<type>* p = node->getParent();
				// test  for null
				if (l == NULL) {
					AVLNode<type>* l1 = node->left;
					// re-arrange nodes
					if (node->key == p->left->key)
						p->left = r;
					else
						p->right = r;

					if (l1->key <= r->key)
						r->left = l1;
					else
						r->right = l1;

					node->left = NULL;
					node->right = NULL;
					delete node;
					rebalance(r);

				}
				else {
					// descent left all the way
					while (l->left != NULL) {
						l = l->left;
					} // end-while
					  // re-arrange right node
					AVLNode<type>* r1 = l->right;

					if (r1 == NULL) {
						l->parent->left = NULL;
					}
					else {
						if (l->parent->key <= r1->key)
							l->parent->left = r1;
						else
							l->parent->right = r1;
					}
					// re-arrange nodes
					l->left = node->left;
					l->right = node->right;
					// test for root
					if (p == NULL) {
						l->parent = NULL;

						root = l;
					}
					else {
						l->parent = p;
						if (p->left->key == node->key)
							p->left = l;
						else
							p->right = l;
					}

					node->left = NULL;
					node->right = NULL;
					delete node;
					rebalance(l);
				}

			}
		this->size--;
	}
};
