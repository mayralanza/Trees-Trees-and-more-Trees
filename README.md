# Trees-Trees-and-more-Trees
Programmed console application that interacts with a general tree, a max heap tree, and a binary tree data structures

Purpose: This program lets users interact with three kinds of Trees that
  hold data. The first one is called, general Tree, because as its name
  indicates holds any kind of data in its leaves. Each TreeNode of the general
  tree have a linked list of its children that allocates memory dynamically,
  which allows user to have multiples leaves in the Linked Tree. Furthermore,
  the next kind of Tree is the Heap Binary Tree that has similar
  characteristics as the queue that can only enqueue the top value. The Max
  Heap Tree hold the maximum key value Treenode in the root. Furthermore, it
  can only delete the root in the Tree. Last but not least, the AVL Tree is a
  a binary and balanced tree (BST) meaning as the user inputs data the Tree
  will be kept balanced by having the low key entries in left, and the high
  ones to the right while having a mean of the nodes keys in the root.        

Authors: <<Team 22>> Mayra Lanza, Giovany Gonzalez

Class: COP-4530-001 Data Structures 

INFORMATION ABOUT THE COMMAND LINE
The command line expects an integer number to navigate through the menu and
submenus. Other inputs will make the program crash and abortion will be 
needed. An example of how the command Line looks:

![projectimage](https://user-images.githubusercontent.com/21368903/28914323-40e2d092-7809-11e7-8257-609a8a87149a.png)

Both the main menu and the submenus have the command number besides the
desired action. Ex.
Wnen enter >> 1 << user will be directed to the General Tree Submenu.
when enter >> 2 << user will be directed to the Max Heap Tree  Submenu.
When enter >> 3 << user will be directed to the AVL Tree submenu.
When enter >> 4 << the program will terminate.
Unlike the Main Menu, the submenus have the cancel option command that lets
users go back to main menu. As result, the program can only be terminated on
the Main Menu.

The three types of Trees are active for the execution of the program. Once
list or table created, users may leave submenus without affecting any data 
information till the program is terminated.

Driver program source code: Main.cpp
other neeeded source code: LinkedTree.h
			   TreeNodeG.h
			   SlinkedList.h
			   Node.h 
			   MaxTree.h
			   TreeNode.h
			   AvlTree.h
			   AVLNode.h
			   mQueue.h
optional code: makefile


PROJECT REPORT - DESIGN INFORMATION 

GENERAL TREE: LinkedTree.h

![projectimg](https://user-images.githubusercontent.com/21368903/28914378-6abc50fa-7809-11e7-8cdf-7af5e3f6111e.png)

 The General Tree has a pointer of the root of the tree, an integer variable
 that hold the size of the tree, and a array of pointer that holds the
 location of all input tree nodes. Moreover, the TreeNodes that are implemeted
 in the Tree hold a Linked list of the Tree nodes children.  Running times of 
 the Linked Tree functions are the following:
 
 Accessors: 
 
 - getRoot() function returns a pointer holding the location of the root in a
   running time of constant O(1).
 - getSize() retrieves the number of Tree nodes created in O(1).
 - getHeight() calculates the height of the Tree in O(n).
 - getDepth() returns the depth of the node in the argument in O(n).
 - empty() bool function that has a constant Runing time of O(1).
 - leaves() returns the number of leaves in the Tree in O(n).
 - siblings() returns the number of the sibligs of the tree node in the
   argument in O(1).
 - findCommonAncestors() finds the common ancestors of a two Tree nodes in
   O(n).
 - findNode() finds the pointer that has the same data parameter in O(n).
 - preorder(), and postorder() have runing time of O(n).
 - levelorder() displays the Tree in O(n^2).
 - buildTree() reads a file in a O(1) constant runing time.
 - clear() function clears the Tree in O(1).
 - insert() function has a running time of O(1).
 - del() deletes a node in a running time of O(n).

MAX HEAP TREE : MaxHeapTree.h

 The Heap Tree consists of: a TreeNode array that holds all the data of the
 Tree, while having its maximun key value at the top of the Tree, a capacity
 that hold the number of buckets that has the array, a count variable that 
 keeps count of the Tree, and a offset that is needed since the Heap Tree
 implementation does not use the 0 position, which help in the resizing of the
 array. In detail, it expands when the array is full, which doubles its
 capacity. However, when data is deleted and the capacity reach one quarter of
 the expanded array it resets to initial capacity. The function running times
 are shown below:
 
 - getMax() gets the Max key values in the tree in O(1) constant running time.   
 - getSize() return the number of the Tree node in the list in O(1). 
 - getHeight() retuns the height value of the Tree in O(1).
 - empty() boolean function return true or false whether the Tree is empty or
   not in O(1).
 - DisplayTree() display the Tree in a running time of O(n).
 - leaves() goes through the Tree and counts the leaves in O(n) time.
 - BuildTree() reads a file in a O(n) running time.
 - clear() function deletes the Tree in O(1) time and set back to initial
   size.
 - insert() inserts values in O(n) runnin time.
 - delMax() deletes the Max key value in the Tree in O(n) since it sorts the
   Tree after deletion.

AVL TREE : AvlTree.h

  The AVL Tree is a binary Tree that keeps balance its subtrees by carefully
  rotating if unbalanced height occurs. The AVL Tree keeps its inputs leaves
  balanced by keeping the height of every node with a difference of at most 
  +1 and -1 of height. The AVL Tree memebers are a root that hold a pointer to
  the location of the root TreeNode, and a size integer count the number of
  tree node the Tree holds. Meanwhile, the TreeNode, of the AVL Tree, Not only
  holds the data and its parent pointer but also has a left and a right
  children. The running times of AVL Tree are as follow:
 - getRoot() function retrieves the pointer of the root in O(1) time.
 - getSize() get the size of the Tree in O(1) running time. 
 - isEmpty() boolean function returns true if empty and false otherwise in
   O(1) running time.
 - leaves() is a recursive function that counts the leaves in the Tree and
   takes O(n) of running time.
 - getDepth() retrieves number of depth of the argument input node in O(1).
 - siblings() gets number of siblings in O(1) running time.
 - postorder(), inorder(), and preorder() take a time od O(n).
 - levelorder() displays values with the help of Queue in a O(n^2).
 - rotateLeft() rotates node in O(1) running time.
 - rotateRight() rotates node in O(1) running time. 
 - rebalence() checks the balance of the Tree and makes adjustments in the
   Tree in O(n) of time.
 - height() gets the height of the given node in a O(n).
 - BuildTree() reads files and inserts them in the Tree in a O(log2n)
   running time.
 - insert() function insert node in O(log2n) running time.
 - find() returns the pointer that hold the data parameter in the function in
   O(log2n) of time.
 - clear() function clear the Tree in a O(n) of running time.
 - del() function deletes data parameter in O(n) of time.       

