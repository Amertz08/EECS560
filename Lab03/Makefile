G=g++ -g -Wall -std=c++11
MAIN=build/main.o
BUCKET=build/bucket.o
QHASH=build/qhash.o
BIN=build/Lab03
ARCH=Mertz_Lab03.tar.gz

main: dir main.o
	$(G) $(MAIN) $(QHASH) $(BUCKET) -o $(BIN)

test:
	$(BIN) data.txt 11 4 5

test1:
	$(BIN) data1.txt 53 10 13

main.o: qhash.o
	$(G) -c main.cpp -o $(MAIN)

qhash.o: bucket.o
	$(G) -c QHashTable.cpp -o $(QHASH)

bucket.o:
	$(G) -c Bucket.cpp -o $(BUCKET)

tar:
	tar -cvf $(ARCH) $(shell find . -type f -name "*.*pp") \
	Makefile readme.txt

dir:
	rm -rf build
	mkdir -p build

clean: dir
	rm $(ARCH)