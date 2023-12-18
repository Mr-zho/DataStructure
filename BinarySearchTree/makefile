BST:doublelinklist.o doublelinklistQueue.o binarySearchTree.o main.o
	gcc doublelinklist.o doublelinklistQueue.o binarySearchTree.o main.o -o BST

doublelinklist.o:doublelinklist.c
	gcc -c doublelinklist.c -o doublelinklist.o

doublelinklistQueue.o:doublelinklistQueue.c
	gcc -c doublelinklistQueue.c -o doublelinklistQueue.o

binarySearchTree.o:binarySearchTree.c
	gcc -c binarySearchTree.c -o binarySearchTree.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	@rm -rf *.o BST