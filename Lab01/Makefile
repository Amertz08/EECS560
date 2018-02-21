CMD=g++ -g -Wall -std=c++11
O=Lab01
LAB=Mertz_$(O)
DIR=./build
BIN=$(DIR)/$(O)
INPUT=data.txt
ARCH_NAME=$(LAB).tar.gz
NODE=$(DIR)/Node.o
LIST=$(DIR)/List.o
MAIN=$(DIR)/Main.o

main: List.o Main.o
	$(CMD) -o $(BIN) $(DIR)/Main.o $(DIR)/Node.o $(DIR)/List.o

test:
	$(BIN) $(INPUT)

Main.o:
	$(CMD) -c main.cpp -o $(MAIN)

Node.o:
	$(CMD) -c Node.cpp -o $(NODE)

List.o: Node.o
	$(CMD) -c LinkedList.cpp -o $(LIST)

mem:
	valgrind --leak-check=yes $(BIN)

tar: tardir
	cp $(shell find . -type f -name "*.*pp") $(INPUT) Makefile $(LAB)
	tar -cvf $(ARCH_NAME) $(LAB)

tardir:
	rm -rf $(LAB)
	mkdir -p $(LAB)

builddir:
	rm -rf $(DIR)
	mkdir -p $(DIR)

dir: tardir builddir

clean: dir
	rm -f $(ARCH_NAME)