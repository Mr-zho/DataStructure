AVL:doublelinklist.o doublelinklistQueue.o balanceBinarySearchTree.o main.o
	gcc -g doublelinklist.o doublelinklistQueue.o balanceBinarySearchTree.o main.o -o AVL

doublelinklist.o:doublelinklist.c
	gcc -g -c doublelinklist.c -o doublelinklist.o

doublelinklistQueue.o:doublelinklistQueue.c
	gcc -g -c doublelinklistQueue.c -o doublelinklistQueue.o

balanceBinarySearchTree.o:balanceBinarySearchTree.c
	gcc -g -c balanceBinarySearchTree.c -o balanceBinarySearchTree.o

main.o:main.c
	gcc -g -c main.c -o main.o

clean:
	@rm -rf *.o AVL