G=g++ -g -Wall -std=c++11
MAIN=build/main.o
BST=build/bst.o
NODE=build/node.o
BIN=build/Lab04
ARCH=Mertz_Lab04.tar.gz

build: dir main.o
	$(G) $(NODE) $(BST) $(MAIN) -o $(BIN)

test:
	$(BIN) data.txt

testcomp:
	$(BIN) complete_tree.txt

testskew:
	$(BIN) skew_tree.txt

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(BIN) data.txt

tar:
	tar -cvf $(ARCH) $(shell find . -type f -name "*.*pp") \
	$(shell find . -type f -name "*.txt") \
	Makefile

main.o: bst.o
	$(G) -c main.cpp -o $(MAIN)

bst.o: node.o
	$(G) -c BinarySearchTree.cpp -o $(BST)

node.o:
	$(G) -c Node.cpp -o $(NODE)

dir:
	rm -rf build
	mkdir -p build

clean: dir
	rm $(ARCH)
