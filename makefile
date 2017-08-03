all: Project3

Project3: Main.o
	g++ Main.o -o project3

Main.0: Main.cpp AvlTree.h LinkedTree.h MaxHeapTree.h mQueue.h Node.h SlinkedList.h TreeNode.h TreeNode AVL.h TreeNodeG.h 
	g++ -c Main.cpp

cleam: 
	rm *o project3
