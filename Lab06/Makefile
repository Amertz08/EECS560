G=g++ -g -Wall -std=c++11
NAME=Mertz_Lab06

BIN=build/Lab06
M=build/Main.o
N=build/Node.o
L=build/List.o
B=build/Bucket.o
D=build/DHash.o
H=build/Hash.o
Q=build/QHash.o
O=build/OHash.o
OBJ=$(M) $(N) $(L) $(B) $(D) $(H) $(Q) $(O)
ARCH=$(NAME).tar.gz


build: dir List.o tables Main.o
	$(G) $(OBJ) -o $(BIN)

test:
	$(BIN)

Main.o: tables List.o
	$(G) -c main.cpp -o $(M)

tables: OHash.o QHash.o DHash.o

OHash.o: Hash.o
	$(G) -c OpenHashTable.cpp -o $(O)

QHash.o: Hash.o
	$(G) -c QHashTable.cpp -o $(Q)

DHash.o: Hash.o
	$(G) -c DHashTable.cpp -o $(D)

Hash.o: Bucket.o
	$(G) -c HashTable.cpp -o $(H)

Bucket.o:
	$(G) -c Bucket.cpp -o $(B)

List.o: Node.o
	$(G) -c LinkedList.cpp -o $(L)

Node.o:
	$(G) -c Node.cpp -o $(N)

tar: dir
	cp $(shell find . -type f -name "*.*pp") \
       	Makefile data.txt report.txt \
       	$(NAME)
	tar -cvf $(ARCH) $(NAME)

dir:
	rm -rf $(NAME)
	mkdir $(NAME)
	rm -rf build
	mkdir build

clean: dir
	rm $(ARCH)
