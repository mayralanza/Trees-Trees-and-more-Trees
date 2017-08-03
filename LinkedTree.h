/********************************************
* Project 3 - Trees. Trees, and more Trees  *
* Team 22: Mayra Lanza                      *
*          Giovany Gonzalez                 *
*          Andrew Walton                    *
*********************************************/
#include "TreeNodeG.h"
#include "SlinkedList.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
template<class type> 
class LinkedTree {
protected: 
		  TreeNodeG<type>* root; 
		   int size;
		  
		   void visit(TreeNodeG<type> *ptr) { 
			   cout << ptr->data << endl; 
		   }

		   TreeNodeG<type>* *arr_data; //Array that keeps track of the inputs 
			//helps on finding node in the tree 
public:
	LinkedTree() : size(0) {
	}

	~LinkedTree() {
		if (this->size != 0) {
			delete[] this->arr_data;
		}
	}

	//ACCESSORS 
	TreeNodeG<type>* getRoot() const {
		return root;
	}

	int getSize() const { 
		return size; 
	}

	bool isEmpty() const { 
		return size == 0; 
	}

	void build_tree() {
		cout << "\nReading text files to build Tree\n";
		ifstream myfile("tree1.txt");
		if (myfile.is_open())
		{
			while (myfile.good())
			{
				string data;
				int parent_key;
				myfile >> data;
				myfile >> parent_key;
				if (myfile.eof()) {
					break;
				}
				TreeNodeG<type>* ptr = findParent(parent_key);
				insert(data, ptr);
			}
			myfile.close();
		}
		else cout << "Unable to open file";
	}

	int getHeight()  { 
		int height = 0;
		TreeNodeG<type>* ptr = getRoot();
		Node<TreeNodeG<type>*>* tmp = ptr->children.getHead();
		if (ptr->children.isEmpty() == true) {
			return height;
		}
		else {
			while (tmp != NULL && tmp->next != NULL) {
				int h1 = 1 + LinkedTree::getHeight(tmp->data,0);
				int h2 = 1 + LinkedTree::getHeight(tmp->next->data,0);
				int h3 = max(h1, h2);
				height = max(h3, height);
				tmp = tmp->next;
			}
		}
		return height;
	}

	int getHeight(TreeNodeG<type>* ptr, int h) {
		Node<TreeNodeG<type>*>* tmp = ptr->children.getHead();
		if (ptr->children.isEmpty() == true) {
			return 0;
		}
		if (ptr->children.isEmpty() != true) {
			h = 1 + getHeight(tmp->data,h);
		}
		while (tmp != NULL && tmp->next != NULL) {
			tmp = tmp->next;
			h = max (h, getHeight(tmp->data,h));
		}
		this->visit(ptr);
		return h;
	} 

	int getDepth(TreeNodeG<type>* ptr) {
		int counter = 0; 
		while (ptr->parent != NULL) {
			counter++; 
			ptr = ptr->parent;
		} 
		return counter;
	} 

	int leaves(TreeNodeG<type>* ptr, int h) {
		Node<TreeNodeG<type>*>* tmp = ptr->children.getHead();
		if (ptr->children.isEmpty() == true) {
			return 1;
		}
		if (ptr->children.isEmpty() != true) {
			h = leaves(tmp->data, h);
		}
		while (tmp != NULL && tmp->next != NULL) {
			tmp = tmp->next;
			h = h + leaves(tmp->data, h);
		}
		this->visit(ptr);
		return h;
	}
	
	TreeNodeG<type>* findCommonAncestors(TreeNodeG<type>* ptr1, TreeNodeG<type>* ptr2) {
		if (this->isEmpty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be compared.");
		}
		if (ptr1->parent == root || ptr2->parent == root) { //The root has no ancestors
			cout << "\nError No common Ancestors" << endl;
			return NULL;
		}  
		int tmp1 = LinkedTree::getDepth(ptr1);
		int tmp2 = LinkedTree::getDepth(ptr2);

		if ( tmp1 > tmp2 ) { 
			while (tmp1 != tmp2) {
				ptr1 = ptr1->parent;
				tmp1 = LinkedTree::getDepth(ptr1);
				tmp2 = LinkedTree::getDepth(ptr2);
			}
		} 
		else {
			if (tmp1 < tmp2) {
				while (tmp1 != tmp2) {
					ptr2 = ptr2->parent;
					tmp1 = LinkedTree::getDepth(ptr1);
					tmp2 = LinkedTree::getDepth(ptr2);
				}
			}
		}

		ptr1 = ptr1->parent;
		ptr2 = ptr2->parent;
		if (getDepth(ptr1) == getDepth(ptr2)) {
			if (ptr1 == ptr2) {
				return ptr1;
			}
			else {
				while (ptr1 != ptr2) {
					ptr1 = ptr1->parent;
					ptr2 = ptr2->parent;
				}
			}
		}
		return ptr1;
	} 

	int siblings(TreeNodeG<type>* ptr) {
		ptr = ptr->parent;
		int count = ptr->children.getSize() - 1;
		return count;
	}

	void preorder(TreeNodeG<type>* ptr) {
		if (this->isEmpty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be displayed.");
		}
		this->visit(ptr);
		Node <TreeNodeG <type>*>* ptr_tmp = ptr->children.getHead();
		if (ptr->children.isEmpty() != true) {
			preorder(ptr_tmp->data);
		}
		while (ptr_tmp != NULL && ptr_tmp->next != NULL) {
			ptr_tmp = ptr_tmp->next;
			preorder(ptr_tmp->data);
		}
	} 

	void postorder(TreeNodeG<type> *ptr) {
		if (this->isEmpty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be displayed.");
		}
		Node<TreeNodeG<type>*>* tmp = ptr->children.getHead();
		if (ptr->children.isEmpty() != true) {
			postorder(tmp->data);
		} 
		while (tmp != NULL && tmp->next != NULL) {
			tmp = tmp->next;
			postorder(tmp->data);
		} 
		this->visit(ptr);
	} 

	void levelorder(TreeNodeG<type> *ptr) {
		if (this->isEmpty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be displayed.");
		}
		this->visit(ptr);
		bool visited = false;
		while (visited == false) {
			for (int i = 0; i < size; i++) {
				TreeNodeG<type> *ptr1 = this->arr_data[i];
				if (ptr1->children.isEmpty() == false) {
					Node<TreeNodeG<type>*>* tmp = ptr1->children.getHead();
					while (tmp != NULL && tmp->next != NULL) {
						this->visit(tmp->data);
						tmp = tmp->next;
					}
					this->visit(tmp->data);
				}
			}
			visited = true;
		}
	}

	TreeNodeG<type>* findNode(type data) {
		if (this->isEmpty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be found.");
		}
		for (int i = 0; i < size; i++) {
			if (this->arr_data[i]->data == data) {
				return this->arr_data[i];
			}
		}
		return NULL; //cant happen!!!
	}

	TreeNodeG<type>* findParent(int key_num) {
		if (key_num == 100) {
			return NULL;
		}
		else
		{
			for (int i = 0; i < size; i++) {
				if (this->arr_data[i]->key == key_num) {
					return this->arr_data[i];
				}
			}
		}
	}

	//MUTATORS
	void insert(const type & data, TreeNodeG<type> *parent) {
		cout << "Inserting " << data << ", parent is ";
		cout << (parent == NULL ? "NULL, this is the root." : parent->data) << endl;
		TreeNodeG<type>* n = new TreeNodeG<type>(data);
		if (parent == NULL) {
			arr_data = new TreeNodeG<type>*[50];
			root = n;
			n->key = 0;
			arr_data[n->key] = n;
			size++;
		}
		else {
			n->parent = parent;
			parent->children.insert(n);
			n->key = size;
			arr_data[n->key] = n;
			size++;
		}
	}

	void clear() {
		delete[] this->arr_data;
		this->size = 0;
		this->root = NULL;
	}

	void del(type data) {
		if (this->isEmpty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be deleted.");
		}
		TreeNodeG<type>* ptr = this->findNode(data); //to be deleted
													 // exit if not found
		if (ptr == NULL)
		{
			cout << "Item [" << data << "] not found in Tree" << endl;
			return;
		}

		TreeNodeG<type>* ptr_p = ptr->parent;
		int idx = -1;
		if (ptr_p == NULL) {  //data to be deleted is the root has no parent
			if (ptr->children.isEmpty()) {
				delete ptr;
				this->size = 0;
				this->root = NULL;
			}
			else { //Root has children
				// get all children of item      
				Node<TreeNodeG<type>*>* first = ptr->children.getHead();
				//TreeNodeG<type>* f  = ptr->children.getHead();
				type data1 = first->data->data;

				// find node
				TreeNodeG<type>* f = this->findNode(data1);

				// remove item
				ptr->children.del(f);

				// remove item from list
				for (int i = 0; i < size; i++) {
					if (this->arr_data[i]->data == data1) {
						idx = i;
						break;
					}
				}
				// shift items
				for (int i = idx; i < size - 1; i++) {
					arr_data[i] = arr_data[i + 1];
				}

				// reset last element
				arr_data[size - 1] = NULL;
				// reset counter
				this->size--;
				// rebuild node
				ptr->data = data1;

			}
		}
		else { //input data has a parent 
			if (!ptr_p->children.isEmpty() && ptr->children.isEmpty()) {
				ptr_p->children.del(ptr);
				// remove item from list
				for (int i = 0; i < size; i++) {
					if (this->arr_data[i]->data == data) {
						idx = i;
						break;
					}
				}
				// shift items
				for (int i = idx; i < size - 1; i++) {
					arr_data[i] = arr_data[i + 1];
				}
				// reset last element
				arr_data[size - 1] = NULL;
				// reset counter
				this->size--;

			}
			else {
				// get all children of item      
				Node<TreeNodeG<type>*>* first = ptr->children.getHead();
				//TreeNodeG<type>* f  = ptr->children.getHead();
				type data1 = first->data->data;

				// find node
				TreeNodeG<type>* f = this->findNode(data1);

				// remove item
				ptr->children.del(f);

				// remove item from list
				for (int i = 0; i < size; i++) {
					if (this->arr_data[i]->data == data1) {
						idx = i;
						break;
					}
				}
				// shift items
				for (int i = idx; i < size - 1; i++) {
					arr_data[i] = arr_data[i + 1];
				}
				// reset last element
				arr_data[size - 1] = NULL;
				// reset counter
				this->size--;
				// rebuild node
				ptr->data = data1;

			}
		}

	}
};
