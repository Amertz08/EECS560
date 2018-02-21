NM=Mertz
L=Lab02
GPP=g++ -g -Wall -std=c++11
LAB=$(NM)_$(L)
ARCH_NAME=$(LAB).tar.gz
B=build
NODE=$(B)/Node.o
LIST=$(B)/List.o
HASH=$(B)/Hash.o
MAIN=$(B)/Main.o
BIN=$(B)/$(L)
IN=data.txt

main: dir Main.o
	$(GPP) $(MAIN) $(HASH) $(LIST) $(NODE) -o $(BIN)

test:
	$(BIN) $(IN)

testno:
	$(BIN)

testbadf:
	$(BIN) blah.txt

builddir:
	rm -rf $(B)
	mkdir $(B)

tardir:
	rm -rf $(LAB)
	mkdir $(LAB)

dir: builddir tardir

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(BIN) data.txt

tar: tardir
	cp $(shell find . -type f -name "*.*pp") \
       	$(IN) Makefile readme.txt \
       	$(LAB)
	tar -cvf $(ARCH_NAME) $(LAB)

Main.o: Hash.o
	$(GPP) -c main.cpp -o $(MAIN)

Hash.o: List.o
	$(GPP) -c HashTable.cpp -o $(HASH)

List.o: Node.o
	$(GPP) -c LinkedList.cpp -o $(LIST)

Node.o:
	$(GPP) -c Node.cpp -o $(NODE)

clean: 	dir
	rm -f $(ARCH_NAME)