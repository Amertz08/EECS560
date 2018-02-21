G=g++ -g -Wall -std=c++11
MAIN=build/main.o
BUCKET=build/bucket.o
HASH=build/hash.o
QHASH=build/qhash.o
DHASH=build/dhash.o
BIN=build/Lab03
LAB=Mertz_Lab03
ARCH=$(LAB).tar.gz
ARGS=53 10 13

main: dir main.o
	$(G) $(BUCKET) $(HASH) $(QHASH) $(DHASH) $(MAIN) -o $(BIN)

test:
	$(BIN) data.txt 11 4 5

test1:
	$(BIN) data1.txt $(ARGS)

test2:
	$(BIN) data2.txt $(ARGS)

test3:
	$(BIN) data3.txt $(ARGS)

test4:
	$(BIN) data4.txt $(ARGS)

test5:
	$(BIN) data5.txt $(ARGS)

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(BIN) data.txt 11 4 5

main.o: qhash.o dhash.o
	$(G) -c main.cpp -o $(MAIN)

dhash.o: hash.o
	$(G) -c DHashTable.cpp -o $(DHASH)

qhash.o: hash.o
	$(G) -c QHashTable.cpp -o $(QHASH)

hash.o: bucket.o
	$(G) -c HashTable.cpp -o $(HASH)

bucket.o:
	$(G) -c Bucket.cpp -o $(BUCKET)

tar: tardir
	cp $(shell find . -type f -name "*.*pp") \
       	Makefile readme.txt data.txt data1.txt data2.txt data3.txt \
       	data4.txt data5.txt observations.txt \
       	$(LAB)
	tar -cvf $(ARCH) $(LAB)

builddir:
	rm -rf build
	mkdir -p build

tardir:
	rm -rf $(LAB)
	mkdir -p $(LAB)

dir: builddir tardir

clean: dir
	rm -rf $(ARCH)
