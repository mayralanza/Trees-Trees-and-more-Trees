/********************************************
* Project 3 - Trees. Trees, and more Trees  *
* Team 22: Mayra Lanza                      *
*          Giovany Gonzalez                 *
*          Andrew Walton                    *
*********************************************/
#include <iostream>
#include <string>
#include <cassert>
#include "LinkedTree.h"
#include "MaxHeapTree.h"
#include "AvlTree.h"
using namespace std;

LinkedTree<string> T;
MaxHeapTree<string> M;
AvlTree<string> A;
// Process command General Tree Selected command state
void Process_General_tree_Cmd()
{
	int op = 0;
	bool flag = false;
	while (true) {
		cout << "********************* General Tree ********************\n";
		cout << "Enter command number or cancel to go back to Main Menu" << endl;
		cout << "1: Create Tree from text file" << endl;
		cout << "2: Insert data to the Tree" << endl;
		cout << "3: Tree siblings/ancestors checker" << endl;
		cout << "4: Empty/size Tree checker" << endl;
		cout << "5: Height/depth of the Tree" << endl;
		cout << "6: Number of leaves checker" << endl;
		cout << "7: Display Tree " << endl;
		cout << "8: Delete data in the Tree" << endl;
		cout << "9: Clear general Tree" << endl;
		cout << "10: Cancel" << endl;
		cout << ">> ";
		cin >> op;
		if (op == 10) break;
		else if (op == 1)
		{
			if (flag == false) {
				cout << endl;
				T.build_tree();
				cout << endl;
				flag = true;
			}
			else {
				cout << "\nThe Tree has been created already\n\n";
			}
		}
		else if (op == 2)
		{
			TreeNodeG<string>* ptr;
			string temp_data;
			string temp_parent;
			if (T.isEmpty() == true) {
				cout << "\nPlease enter the data to be inserted >> ";
				cin >> temp_data;
				T.insert(temp_data, NULL);
				cout << endl << endl;
			}
			else {
				cout << "Please enter data for the new Tree node >> ";
				cin >> temp_data;
				cout << "Please enter name of the parent of the node >> ";
				cin >> temp_parent;
				ptr = T.findNode(temp_parent);
				T.insert(temp_data, ptr);
				cout << endl << endl;
			}
		}
		else if (op == 3)
		{
			int tmp;
			cout << "\nEnter command number\n";
			cout << "1: Number of sibling checker" << endl;
			cout << "2: Common ancestors checker" << endl;
			cout << ">> ";
			cin >> tmp;
			if (tmp == 1) {
				TreeNodeG<string>* ptr;
				string temp;
				cout << "Please enter name of the node to get number of siblings >> ";
				cin >> temp;
				ptr = T.findNode(temp);
				int siblings = T.siblings(ptr);
				cout << "The number of siblings of " << temp << " is " << siblings;
				cout << endl << endl;
			}
			else if (tmp == 2) {
				TreeNodeG<string>* ptr1;
				TreeNodeG<string>* ptr2;
				string temp1;
				string temp2;
				cout << "Please enter the first node to be compared >> ";
				cin >> temp1;
				cout << "Please enter the second node to be compared >> ";
				cin >> temp2;
				ptr1 = T.findNode(temp1);
				ptr2 = T.findNode(temp2);
				TreeNodeG<string>* ptr3 = T.findCommonAncestors(ptr1, ptr2);
				cout << "\nCommon ancestors: " << ptr3->getData() << " ";
				while (ptr3->getParent() != NULL) {
					ptr3 = ptr3->getParent();
					cout << ptr3->getData() << " ";
				}
				cout << endl << endl;
			}
			else {
				cout << "\nWrong command input try again\n";
				cout << endl << endl;
			}	
		}
		else if (op == 4)
		{
			int tmp;
			cout << "\nEnter command number\n";
			cout << "1: Empty Tree checker" << endl;
			cout << "2: Size of the Tree" << endl;
			cout << ">> ";
			cin >> tmp;
			if (tmp == 1) {
				cout << endl;
				cout << (T.isEmpty() ? "The Tree is empty" : "The Tree is not empty") << endl;
				cout << endl;
			}
			else if (tmp == 2) {
				cout << "\nThe size of the Tree is " << T.getSize() << endl << endl;
			}
			else {
				cout << "\nWrong command input try again\n";
				cout << endl << endl;
			}
		}
		else if (op == 5)
		{
			int tmp;
			cout << "\nEnter command number\n";
			cout << "1: Height checker" << endl;
			cout << "2: Depth checker" << endl;
			cout << ">> ";
			cin >> tmp;
			if (tmp == 1) {
				int tmp1;
				cout << "\nEnter command number\n";
				cout << "1: Tree height" << endl;
				cout << "2: Node/subtree height" << endl;
				cout << ">> ";
				cin >> tmp1;
				if (tmp1 == 1) {
					cout << "The height of the tree is " << T.getHeight() << endl << endl;
				}
				else if (tmp1 = 2) {
					TreeNodeG<string>* ptr;
					string node;
					cout << "Enter subtree node name >> ";
					cin >> node;
					ptr = T.findNode(node);
					int height = T.getHeight(ptr,0);
					cout << "The height of the " << node << " subtree is " << height << endl << endl; 
				}
			}
			else if (tmp == 2) {
				TreeNodeG<string>* ptr;
				string node;
				cout << "Enter node name to get depth >> ";
				cin >> node;
				ptr = T.findNode(node);
				int depth = T.getDepth(ptr);
				cout << "The depth of " << node << " is " << depth << endl << endl;
			}
			else {
				cout << "\nWrong command input try again\n";
				cout << endl << endl;
			}
		}
		else if (op == 6)
		{
			//leaves
			cout << "\nThere is/are " << T.leaves(T.getRoot(),0) << " leave(s) in the Tree\n\n";
		}
		else if (op == 7)
		{
			int tmp; 
			cout << "\nEnter command number\n";
			cout << "1: Level order Tree display" << endl;
			cout << "2: Preorder Tree display" << endl;
			cout << "3: Postorder Tree display" << endl;
			cout << ">> ";
			cin >> tmp;
			if (tmp == 1) {
				try {
					cout << "\n******* LEVEL ORDER DISPLAY *******\n";
					T.levelorder(T.getRoot());
					cout << "************  End Tree ************\n";
				}
					catch (const exception & e)
					{
						cout << "\nError >> " << e.what() << endl << endl;
					}
						cout << endl;
					}
			else if (tmp == 2) {
				try{
				cout << "\n******* PREORDER DISPLAY *******\n";
				T.preorder(T.getRoot());
				cout << "************  End Tree ************\n";
				}
				catch (const exception & e)
				{
					cout << "\nError >> " << e.what() << endl;
				}
				cout << endl ;
			}
			else if (tmp == 3) {
				try{
					cout << "\n******** POSTORDER DISPLAY *******\n";
					T.postorder(T.getRoot());
					cout << "************  End Tree ************\n";
					}
				catch (const exception & e)
					{
						cout << "\nError >> " << e.what() << endl;
					}
					cout << endl;
			}
		}
		else if (op == 8)
		{
			//delete data
			try {
				string tmp;
				cout << "Please enter data to be deleted in the Tree >> ";
				cin >> tmp;
				T.del(tmp);
				cout << endl << endl;
			}
			catch (const exception & e)
			{
				cout << "\nError >> " << e.what() << endl << endl;
			}
		}
		else if (op == 9)
		{
			//clear tree
			T.clear();
			cout << "\nThe Tree has been cleared\n\n";
			flag = false;
		}
		else {
			cout << "Invalid input. Trt again\n";
		}
	}
}

// Process command Heap Selected command state
void Process_Heap_Cmd()
{
	int op = 0;
	bool flag = false;
	while (true) {
		cout << "******************* Heap Submenu *********************" << endl;
		cout << "Enter command number or cancel to go back to Main Menu" << endl;
		cout << "1: Create Tree from text file" << endl;
		cout << "2: Add data to the MaxHeap Tree" << endl;
		cout << "3: Get size, height and leaves of the MaxHeap Tree" << endl;
		cout << "4: Delete or Get Max Value " << endl;
		cout << "5: Empty MaxHeap Tree checker " << endl;
		cout << "6: Clear list" << endl;
		cout << "7: Display MaxHeap Tree" << endl;
		cout << "8: Cancel" << endl;
		cout << ">> ";
		cin >> op;
		if (op == 8) {
			cin.get();
			break;
		}
		else if (op == 1)
		{
			if (flag == false) {
				cout << endl;
				M.BuildTree();
				M.DisplayTree();
				cout << endl;
				flag = true;
			}
			else {
				cout << "\nThe Heap Tree has been created already\n\n";
			}
		}
		else if (op == 2)
		{
			int key;
			string data;
			cout << "\nPlease enter key for the data to be inserted >> ";
			cin >> key;
			cout << "Please enter data to be stored  >> ";
			cin >> data;
			M.insert(key, data);
			cout << endl;
		}
		else if (op == 3)
		{
			cout << "\nThe size of the MaxHeap Tree is " << M.getSize() << endl;
			cout << "\nThe height of the MaxHeap Tree is " << M.getHeight() << endl;
			cout << "\nThe number of leaves of the MaxHeap Tree is " << M.leaves() << endl << endl;
		}
		else if (op == 4)
		{
			int tmp;
			cout << "\nEnter command number\n";
			cout << "1: Delete Max" << endl;
			cout << "2: Get Max" << endl;
			cout << ">> ";
			cin >> tmp;
			if (tmp == 1) {
				cout << endl;
				M.delMax();
				cout << "\nThe max of the MaxHeap Tree has been deleted " << endl << endl;
			}
			else if (tmp == 2) {
				cout << "\nThe max of the MaxHeap Tree is " << M.getMax() << endl << endl;
			}
			else {
				cout << "\nWrong command input try again\n";
				cout << endl << endl;
			}

		}
		else if (op == 5)
		{
			cout << endl;
			cout << (M.empty() ? "The Tree is empty" : "The Tree is not empty") << endl << endl;
		}
		else if (op == 6)
		{
			M.clear();
			cout << "\n The Max Heap Tree has been cleared " << endl << endl;
			flag = false;
		}
		else if (op == 7)
		{
			try {
				M.DisplayTree();
			}
			catch (const exception & e)
			{
				cout << "\nError >> " << e.what() << endl << endl;
			}
		}
		else {
			cout << "Invalid input try again\n";
			cin.get();
		}
	}
}

// Process AVL Tree command Stack 
void Process_AVL_Tree_Cmd()
{
	int op = 0;
	bool flag = false;
	while (true) {
		cout << "****************** AVL Tree subenu **********************\n";
		cout << "Enter command number or cancel to go back to Main Menu" << endl;
		cout << "1: Create Tree from text file" << endl;
		cout << "2: Add data to the AVL Tree" << endl;
		cout << "3: Get height, leaves, and siblings in the AVL Tree" << endl;
		cout << "4: Empty/size/root Tree checker " << endl;
		cout << "5: Delete Data " << endl;
		cout << "6: Clear AVL Tree" << endl;
		cout << "7: Display AVL Tree" << endl;
		cout << "8: Cancel" << endl;
		cout << ">> ";
		cin >> op;
		if (op == 8) break;
		else if (op == 1)
		{
			if (flag == false) {
				cout << endl;
				A.BuildTree();
				A.levelorder();
				cout << endl;
				flag = true;
			}
			else {
				cout << "\nThe AVL Tree has been created already\n\n";
			}

		}
		else if (op == 2)
		{
			int key;
			string data;
			cout << "\nPlease enter key for the data to be inserted >> ";
			cin >> key;
			cout << "Please enter data to be stored  >> ";
			cin >> data;
			A.insert(data, key);
			cout << endl;
		}

		else if (op == 3)
		{
			int tmp1;
			cout << "\nEnter command number\n";
			cout << "1: Tree height" << endl;
			cout << "2: Node/subtree height" << endl;
			cout << "3: Leaves in the Tree" << endl;
			cout << "4: Siblings " << endl;
			cout << ">> ";
			cin >> tmp1;
			if (tmp1 == 1) {
				cout << "The height of the tree is " << A.height() << endl << endl;
			}
			else if (tmp1 == 2) {
				AVLNode<string>* ptr;
				int key;
				cout << "Enter subtree node key >> ";
				cin >> key;
				ptr = A.find(key);
				int height = A.height(ptr);
				cout << "The height of the " << ptr->getData() << " subtree is " << height << endl << endl;
			}
			else if (tmp1 == 3) {
				cout << "There are " << A.leaves(A.getRoot()) << " leaves in the AVL Tree \n\n";
			}
			else if (tmp1 == 4) {
				//siblings
				AVLNode<string>* ptr1;
				int key;
				cout << "Enter subtree node key >> ";
				cin >> key;
				ptr1 = A.find(key);
				if (A.siblibgs(ptr1) == -1) {
					cout << "This is the Root, which has no siblings\n\n";
				}
				else {
					cout << "\nThe Tree node " << ptr1->getData() << " , " << ptr1->getKey() << " has ";
					cout << A.siblibgs(ptr1) << " sibling(s).\n\n";
				}
			}
		}
		else if (op == 4)
		{
			int tmp4;
			cout << "\nEnter command number\n";
			cout << "1: Empty Tree checker" << endl;
			cout << "2: Size Tree checker" << endl;
			cout << "3: Root of the Tree" << endl;
			cout << ">> ";
			cin >> tmp4;
			if (tmp4 == 1) {
				cout << endl;
				cout << (A.isEmpty() ? "The Tree is empty" : "The Tree is not empty") << endl;
				cout << endl;
			}
			else if (tmp4 == 2) {
				cout << "There are " << A.getSize() << " Tree nodes in the AVL Tree \n\n";
			}
			else if (tmp4 == 3) {
				try{
				cout << "The root of the Tree is " << A.getRoot()->getData() << " , " << A.getRoot()->getKey()  << "\n\n";
				}
				catch (const exception & e)
				{
					cout << "\nError >> " << e.what() << endl << endl;
				}
				cout << endl;
			}
			else {
				cout << "Invalid input. Trt again\n";
			}
			
		}
		else if (op == 5)
		{
			//delete
			try {
				int tmp;
				cout << "Please enter key to be deleted in the Tree >> ";
				cin >> tmp;
				A.del(tmp);
				cout << endl << endl;
			}
			catch (const exception & e)
			{
				cout << "\nError >> " << e.what() << endl << endl;
			}
		}
		else if (op == 6)
		{
			//clear
			A.clear(A.getRoot());
			cout << "\nThe AVL has been cleared \n\n";
			flag = false;
		}
		else if (op == 7)
		{
			int tmp;
			cout << "\nEnter command number\n";
			cout << "1: Level order Tree display" << endl;
			cout << "2: Preorder Tree display" << endl;
			cout << "3: Postorder Tree display" << endl;
			cout << "4: Inorder Tree display" << endl;
			cout << ">> ";
			cin >> tmp;
			if (tmp == 1) {
				try {
					cout << "\n******* LEVEL ORDER DISPLAY *******\n";
					A.levelorder();
					cout << "************  End Tree ************\n";
				}
				catch (const exception & e)
				{
					cout << "\nError >> " << e.what() << endl << endl;
				}
				cout << endl;
			}
			else if (tmp == 2) {
				try {
					cout << "\n******* PREORDER DISPLAY *******\n";
					A.preorder();
					cout << "************  End Tree ************\n";
				}
				catch (const exception & e)
				{
					cout << "\nError >> " << e.what() << endl;
				}
				cout << endl;
			}
			else if (tmp == 3) {
				try {
					cout << "\n******** POSTORDER DISPLAY *******\n";
					A.postorder();
					cout << "************  End Tree ************\n";
				}
				catch (const exception & e)
				{
					cout << "\nError >> " << e.what() << endl;
				}
				cout << endl;
			}
			else if (tmp == 4) {
				try {
					cout << "\n********** INORDER DISPLAY *********\n";
					A.inorder();
					cout << "************  End Tree ************\n";
				}
				catch (const exception & e)
				{
					cout << "\nError >> " << e.what() << endl;
				}
				cout << endl;
			}
		}
		else {
			cout << "Invalid input. Trt again\n";
		}
	}
}

int main()
{
	cout << "\n    Project 3 - Trres. Trees, and more Trees\n";
	int op = 0;
	while (true) {
		cout << "****************** Main Menu ******************" << endl;
		cout << "Enter command to get into desired submenu\n";
		cout << "1: General Tree" << endl;
		cout << "2: Heap Tree" << endl;
		cout << "3: AVL Tree" << endl;
		cout << "4: Quit" << endl;
		cout << ">> ";
		cin >> op;
		if (op == 4) break;
		else if (op == 1) {
			cout << endl;
			Process_General_tree_Cmd();
		}
		else if (op == 2) {
			cout << endl;
			Process_Heap_Cmd();
		}
		else if (op == 3) {
			cout << endl;
			Process_AVL_Tree_Cmd();
		}
		else {
			cout << "Invalid input. Trt again\n";
		}
		cout << endl << endl;
	}

	cout << "Normal Termination\n" << endl;
	cin.get();
	return 0;
}
