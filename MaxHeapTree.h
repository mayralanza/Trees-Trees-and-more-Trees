/********************************************
* Project 3 - Trees. Trees, and more Trees  *
* Team 22: Mayra Lanza                      *
*          Giovany Gonzalez                 *
*          Andrew Walton                    *
*********************************************/
#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

const int treeCapacity = 2;

template<class Type>
class MaxHeapTree {
private:
	TreeNode<Type> *Tree;

	int capacity; // capacity
	int count; // number of elements in tree
	int offset; // need offset since we don't use the 0 postion of the array/

public:

	//Constructors
	MaxHeapTree() : count(0) {
		capacity = treeCapacity;
		offset = capacity + 1;
		TreeNode<Type> *tmp = new TreeNode<Type>[offset];
		Tree = tmp;
	};

	// Destructors
	~MaxHeapTree() {
		delete[] Tree;
	}
	// Accesors
	int getMax() {
		int root;

		TreeNode<Type> ptr = Tree[1];
		root = ptr.getKey();
		return root;
	};

	int getSize() const {
		return count;
	};

	int getHeight() const {
		int height = 0, idx = 2;
		//
		if (count <= 1)
			return 0;

		while (idx <= count)
		{
			idx = idx * 2;
			height++;
		}
		//
		return height;
	};

	bool empty() const {
		return count == 0;
	};

	void DisplayTree() {
		if (this->empty()) {//check if the list is empty
			throw underflow_error("The Tree is empty. No Tree nodes can be displayed.");
		}
		TreeNode<Type> p;
		int idx = 2;
		string strTabs = "";
		//
		cout << "************ Heap Tree ************" << endl;

		for (int i = 1; i <= count; i++) {
			p = Tree[i];
			if (i == idx) {
				strTabs = strTabs + "    ";
				idx = idx * 2;
				cout << endl;
			}

			cout << strTabs << p.getKey() << "/" << p.getData() << endl;
		}

		cout << "************  End Tree ************" << endl << endl;
	}

	int leaves() const {
		int leafCount = 0;
		// 2i and 2i + 1
		for (int i = 1; i <= count; i++) {
			if (!((2 * i) <= count || ((2 * i) + 1) <= count)) {
				leafCount++;
			}
		}

		return leafCount;
	};

	// Mutators

	void BuildTree() {
		string line;
		ifstream myfile("tree.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				if (line.length() > 0) {
					int pos = line.find(' ');
					string data = line.substr(0, pos);
					string str = line.substr(pos + 1);
					// add node
					this->insert(atoi(str.c_str()), data);
				}
			}
			//close file
			myfile.close();
		}
		else
			cout << "Unable to open file";

	};

	void clear() {

		offset = treeCapacity + 1;

		delete[] Tree;
		// resize to initial size

		TreeNode<Type> *tmp = new TreeNode<Type>[offset];
		Tree = tmp;
		count = 0;
	};


	void insert(int key, Type data) {
		// resize
		count++;

		if (count > capacity) {  // array is full so double capacity
			capacity = capacity * 2;

			offset = capacity + 1;
			TreeNode<Type> *tmp = new TreeNode<Type>[offset];

			//copy current aray
			for (int i = 1; i < count; i++) {
				TreeNode<Type> *p = &Tree[i];
				tmp[i] = *p;
			}

			delete[] Tree;
			Tree = tmp;
		}

		// insert new item

		TreeNode<Type> *ptr = new TreeNode<Type>(key, data);
		Tree[count] = *ptr;

		TreeNode<Type> parent;
		int parent_idx, last_idx = count;
		//
		// parent: position / 2
		// bubble up
		while (true)
		{
			parent_idx = last_idx / 2;
			//
			if (parent_idx < 1)
				break;
			//
			parent = Tree[parent_idx];
			int val = parent.getKey();
			//
			if (key > val) {
				// do swap
				Tree[parent_idx] = *ptr;
				Tree[last_idx] = parent;
				last_idx = parent_idx;
				//
				if (last_idx < 1)
					break;
			}
			else
				break;

		}

	};

	void delMax() {
		if (count < 1)
			return;
		else if (count == 1) {
			TreeNode<Type> *p3 = &Tree[1];
			//delete p3;
			count--;
			return;
		}

		int left_idx, right_idx, idx, current_idx = 1;

		TreeNode<Type> *p = &Tree[count];
		TreeNode<Type> *r = &Tree[current_idx];
		TreeNode<Type> n1;

		Tree[current_idx] = *p;

		r = &n1;
		Tree[count] = n1;

		count--;

		if (count <= 1)
			return;
		// bubble down: if current is less then either child (starting from left)
		// children: 2i, 2i + 1
		while (true) {
			// calculate indexes
			left_idx = current_idx * 2;
			right_idx = (current_idx * 2) + 1;
			// validate indexes
			if (left_idx > count && right_idx > count) {
				break;
			}
			else if (right_idx > count) {
				idx = left_idx;
			}
			else {
				if (Tree[left_idx].getKey() > Tree[right_idx].getKey()) {
					idx = left_idx;
				}
				else {
					idx = right_idx;
				}
			}
			//
			if (Tree[idx].getKey() > Tree[current_idx].getKey()) {
				// swap

				TreeNode<Type> *p2 = &Tree[idx];
				TreeNode<Type> *q1 = new TreeNode<Type>(Tree[current_idx].getKey(), Tree[current_idx].getData());

				Tree[current_idx] = *p2;
				Tree[idx] = *q1;
				// reset
				current_idx = idx;
			}
			else {
				break;
			}
		}	// end-while
			// resize
		if (capacity / 4 >= count && capacity > treeCapacity) {
			capacity = capacity / 2;
			// reset if less than initial-size
			cout << "new capacity" << capacity << endl;
			if (capacity < treeCapacity) {
				capacity = treeCapacity;
			}
			offset = capacity + 1;
			TreeNode<Type> *tmp = new TreeNode<Type>[offset];
			cout << endl << "Offset is : " << offset << endl;
			//copy current aray
			for (int i = 1; i <= count; i++) {
				TreeNode<Type> *p = &Tree[i];
				tmp[i] = *p;
			}

			delete[] Tree;
			Tree = tmp;
		}

	};


};