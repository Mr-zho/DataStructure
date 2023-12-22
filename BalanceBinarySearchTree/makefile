BST:doublelinklist.o doublelinklistQueue.o balanceBinarySearchTree.o main.o
	gcc doublelinklist.o doublelinklistQueue.o balanceBinarySearchTree.o main.o -o BST

doublelinklist.o:doublelinklist.c
	gcc -c doublelinklist.c -o doublelinklist.o

doublelinklistQueue.o:doublelinklistQueue.c
	gcc -c doublelinklistQueue.c -o doublelinklistQueue.o

balanceBinarySearchTree.o:balanceBinarySearchTree.c
	gcc -c balanceBinarySearchTree.c -o balanceBinarySearchTree.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	@rm -rf *.o BST