GPP=g++ -g -Wall -std=c++11
ARCH_NAME=Mertz_Lab02.tar.gz
NODE=build/Node.o
LIST=build/List.o
HASH=build/Hash.o
MAIN=build/Main.o
BIN=build/Lab02
IN=data.txt

main: Main.o
	$(GPP) $(MAIN) $(HASH) $(LIST) $(NODE) -o $(BIN)

test:
	$(BIN) $(IN)

tar:
	tar -cvf $(ARCH_NAME) $(shell find . -type f -name "*.*pp") $(IN) Makefile

Main.o: Hash.o
	$(GPP) -c main.cpp -o $(MAIN)

Hash.o: List.o
	$(GPP) -c HashTable.cpp -o $(HASH)

List.o: Node.o
	$(GPP) -c LinkedList.cpp -o $(LIST)

Node.o:
	$(GPP) -c Node.cpp -o $(NODE)

clean:
	rm -rf ./build
	mkdir ./build
	rm $(ARCH_NAME)