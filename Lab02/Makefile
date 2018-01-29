GPP=g++ -g -Wall -std=c++11
ARCH_NAME=Mertz_Lab02.tar.gz

main: Main.o
	$(GPP) -o build/Lab02 build/Main.o build/Hash.o build/Node.o build/List.o

test:
	build/Lab02 data.txt

tar:
	tar -cvf $(ARCH_NAME) $(shell find . -type f -name "*.*pp") data.txt Makefile

Main.o: Hash.o
	$(GPP) -c main.cpp -o build/Main.o

Hash.o: List.o
	$(GPP) -c HashTable.cpp -o build/Hash.o

Node.o:
	$(GPP) -c Node.cpp -o build/Node.o

List.o: Node.o
	$(GPP) -c LinkedList.cpp -o build/List.o


clean:
	rm -rf ./build
	mkdir ./build
	rm $(ARCH_NAME)