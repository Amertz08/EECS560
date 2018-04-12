G=g++ -g -Wall -std=c++11
NAME=Mertz_Lab09
BST=build/bst.o
N=build/node.o
HP=build/heap.o
MAX=build/max.o
MIN=build/min.o
M=build/main.o
BIN=build/Lab09

main: dir main.o
	$(G) -o $(BIN) $(M) $(MAX) $(MIN) $(HP) $(BST) $(N)

test:
	$(BIN)

main.o: max.o min.o bst.o
	$(G) -c main.cpp -o $(M)

max.o: heap.o
	$(G) -c MaxHeap.cpp -o $(MAX)

min.o: heap.o
	$(G) -c MinHeap.cpp -o $(MIN)

heap.o:
	$(G) -c KHeap.cpp -o $(HP)

bst.o: node.o
	$(G) -c BinarySearchTree.cpp -o $(BST)

node.o:
	$(G) -c node.cpp -o $(N)

tar: tardir
	cp $(shell find . -type f -name "*.*pp") \
		Makefile $(NAME).pdf \
		$(NAME)
	tar -cvf $(NAME).tar.gz $(NAME)

tardir:
	rm -rf $(NAME)
	mkdir -p $(NAME)

dir:
	rm -rf build
	mkdir -p build