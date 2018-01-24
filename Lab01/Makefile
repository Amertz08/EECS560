CMD=g++ -g -Wall -std=c++11
O=Lab01
DIR=./build
MAIN=$(DIR)/$(O)
INPUT=data.txt
ARCH_NAME=Mertz_Lab01.tar.gz

main: List.o Main.o
	$(CMD) -o $(MAIN) $(DIR)/Main.o $(DIR)/Node.o $(DIR)/List.o

run:
	$(MAIN) $(INPUT)

Main.o:
	$(CMD) -c main.cpp -o $(DIR)/Main.o

Node.o:
	$(CMD) -c Node.cpp -o $(DIR)/Node.o

List.o: Node.o
	$(CMD) -c LinkedList.cpp -o $(DIR)/List.o

mem:
	valgrind --leak-check=yes $(MAIN)

tar:
	tar -cvf $(ARCH_NAME) $(shell find . -type f -name "*.*pp") data.txt Makefile

clean:
	rm -rf ./build
	mkdir ./build
	rm $(ARCH_NAME)