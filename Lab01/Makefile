CMD=g++ -g -Wall -std=c++11
O=Lab01
DIR=./build
BIN=$(DIR)/$(O)
INPUT=data.txt
ARCH_NAME=Mertz_Lab01.tar.gz
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

tar:
	tar -cvf $(ARCH_NAME) $(shell find . -type f -name "*.*pp") $(INPUT) Makefile

clean:
	rm -rf $(DIR)
	mkdir $(DIR)
	rm -f $(ARCH_NAME)