G=g++ -g -Wall -std=c++11

BIN=build/Lab05
M=build/Main.o
T=build/Tree.o
N=build/Node.o
ARCH=Mertz_Lab05.tar.gz

build: dir Main.o
	$(G) $(N) $(T) $(M) -o $(BIN)

test:
	$(BIN)

Main.o: Tree.o
	$(G) -c main.cpp -o $(M)

Tree.o: Node.o
	$(G) -c TwoThreeTree.cpp -o $(T)

Node.o:
	$(G) -c Node.cpp -o $(N)

tar:
	tar -cvf $(ARCH) $(shell find . -type f -name "*.*pp") \
	data.txt Makefile

dir:
	rm -rf build
	mkdir build

clean: dir
	rm $(ARCH)