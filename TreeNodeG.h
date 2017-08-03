/********************************************
* Project 3 - Trees. Trees, and more Trees  *
* Team 22: Mayra Lanza                      *
*          Giovany Gonzalez                 *
*          Andrew Walton                    *
*********************************************/
#include <iostream>
#include <fstream>
#include "SlinkedList.h"
using namespace std;
template<class Type>
class TreeNodeG {
protected:
	int key;
	Type data;
	TreeNodeG* parent; //parent index
	SLinkedList<TreeNodeG*> children; //Children Linked list  
	template<class U> 
	friend class LinkedTree;

public:
	TreeNodeG():data(0), key(0), parent(NULL), children(NULL) {
	}

	TreeNodeG(const Type & data) : parent(NULL) {
		this->data = data;
	}

	TreeNodeG(const Type & data, TreeNodeG * parent){
	this->data = data;
	this->parent = parent;
	}

	Type getData() const {
		return this->data;
	}

	int getKey() const {
		return this->key;
	}
	
	TreeNodeG* getParent() const {
		return this->parent;
	}

};
