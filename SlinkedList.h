#ifndef LIST
#define LIST
#include "Node.h"
#include<iostream>
#include<cassert>
#include <stdexcept>      // std::exception
using namespace std;

template <class T> class SLinkedList {
protected:
	Node<T> *head;
	int sz;
public:
	SLinkedList() :sz(0), head(NULL) {
	}
	~SLinkedList() {
		Node<T>* current = head;
		while (current != 0) {
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
		head = 0;
	}

	Node<T>* getHead() const{
		return head;
	}
	bool isEmpty() const {
		return head == NULL;
	}
	int getSize() const {
		return sz;
	}

	void insert(const T & data) {
		Node<T> *tmp = new Node<T>(data);
		if (head == NULL) {
			head = tmp;
			sz++;
		}
		else {
			Node<T> *ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = tmp;
			sz++;
		}
		//return tmp;
	}
	void insert(const T & data, int pos) {
		if (pos <= 0) {
			Node<T> *tmp = new Node<T>(data, head);
			head = tmp;
			sz++;
		}
		else if (pos > sz) {
			SLinkedList::insert(data);
		}
		else {
			Node<T> *ptr = head;
			int k = 1;
			while (ptr->next != NULL) {
				if (k == pos - 1) {
					Node<T> *tmp = new Node<T>(data);
					tmp->next = ptr->next;
					ptr->next = tmp;
					sz++;
					break;
				}
				else {
					ptr = ptr->next;
					k++;
				}
			}
		}

	}

	 void del(const T &  data) {
              if (this->isEmpty()) {//check if the list is empty
                     throw underflow_error("You cannot delete something when there's nothing to delete.");
              }
              Node<T>* prev = this->head;
              Node<T>* ptr = this->head;
 
                     if (ptr->next == NULL && ptr->data == data) {
                           delete this->head;
                           head = NULL;
                           this->sz--;
                     }
                     else
                     {
                           //search for item
                           //while (ptr == NULL && ptr->next != NULL) {
                           while (ptr != NULL) {

							   if (ptr->data == data) {
                                         if (ptr == head) {
                                                this->head = head->next;
                                                delete prev;
                                                sz--;
                                         }
                                         else {
                                                Node<T> *tmp = ptr->next;
                                                /*
                                                ptr->id = ptr->next->id;
                                                ptr->data = ptr->next->data;
                                                ptr->next = ptr->next->next;
                                                delete tmp;
                                                */
                                                prev->next = tmp;
                                                delete ptr;
                                                // reset counter
                                                sz--;
                                                break;
                                         }
                                  }
                                  prev = ptr;
                                  ptr = ptr->next;
                           }
                           /*
                           if (ptr->data == data) {
                                  prev->next = NULL;
                                  delete ptr;
                                  sz--;
                           }
                           */
              }
       }
	void printList() const {
		Node<T> *ptr = head;
		while (ptr->next != NULL) {
			cout << "Node[" << ptr->id << "]= '" << ptr->data << "'-->";
			ptr = ptr->next;
		}
		cout << "Node[" << ptr->id << "]= '" << ptr->data << "'-->";
		cout << "end" << endl;
	}

};
#endif
