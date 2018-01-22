CMD=g++ -g -Wall -std=c++11
O=Lab01
DIR=./build
MAIN=$(DIR)/$(O)
INPUT=data.txt

main: Main.o Node.o List.o
	$(CMD) -o $(MAIN) $(DIR)/Main.o $(DIR)/Node.o $(DIR)/List.o

run:
	$(MAIN) $(INPUT)

Main.o:
	$(CMD) -c main.cpp -o $(DIR)/Main.o

Node.o:
	$(CMD) -c Node.cpp -o $(DIR)/Node.o

List.o:
	$(CMD) -c LinkedList.cpp -o $(DIR)/List.o

clean:
	rm -rf ./build
	mkdir ./build