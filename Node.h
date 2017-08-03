#ifndef NODE
#define NODE
#include<iostream>
static int num_ = 0;
template<class type>
class Node {
public:
	type data;
	Node * next;
	int id;
	
	Node() :data(0), next(0) {
		id = num_++;
	}

	Node(const type & data) :next (NULL){
		this->data = data;
		id = num_++;
	}
	Node(const type & data, Node * next) {
		this->data = data;
		this->next = next;
		id = num_++;
	}

};
#endif
