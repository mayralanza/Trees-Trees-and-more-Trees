#pragma once
#include "SlinkedList.h"

template<class type>
class mQueue :public SLinkedList<type> {
private:
	Node<type> *tail;
public:
	//Constructor
	mQueue() :tail(NULL) {
		// cout << "from queue" << endl;
	}
	bool isEmpty() const {
		return SLinkedList<type>::isEmpty();
	}

	type front() const {
		if (this->isEmpty()) throw underflow_error("Queue empty");
		return SLinkedList<type>::head->data;
	}

	type back() const {
		if (this->isEmpty()) throw underflow_error("Queue empty");
		return tail->data;

	}

	void enqueue(const type & data) {
		Node<type> *n = new Node<type>(data);
		//cout << "node address " << n << endl;
		if (this->isEmpty()) {
			SLinkedList<type>::head = n;
			tail = n;
			SLinkedList<type>::sz++;
		}
		else {
			tail->next = n;
			tail = n;
			SLinkedList<type>::sz++;
		}
	}

	type dequeue() {
		type d = this->front();
		Node<type> *ptr = SLinkedList<type>::head;
		SLinkedList<type>::head = ptr->next;
		delete ptr;
		ptr = NULL;
		SLinkedList<type>::sz--;
		return d;
	}


	void display() {
		int sz = SLinkedList<type>::getSize();
		while (sz>0) {
			type tmp = this->dequeue();
			cout << tmp << endl;
			this->enqueue(tmp);
			sz--;
		}
	}
	void static display(mQueue<type> & Q) {
		mQueue<type> Qtmp;
		while (!Q.isEmpty()) {
			type d = Q.dequeue();
			Qtmp.enqueue(d);
			cout << d << "->";
		}
		cout << "back" << endl;
		Q = Qtmp;
	}

};
