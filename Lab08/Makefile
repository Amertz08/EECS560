G=g++ -g -Wall -std=c++11
N=Mertz_Lab08
BIN=build/Lab08
TBIN=build/test
T=build/test.o
MIN=build/minmax.o
MAX=build/maxmin.o
H=build/heap.o
M=build/main.o

build: test main

runmain:
	$(BIN)

runtest:
	$(TBIN)

test: test.o
	$(G) -o $(TBIN) $(T) $(H) $(MIN) $(MAX)

main: main.o
	$(G) -o $(BIN) $(M) $(H) $(MIN) $(MAX)

main.o: minmax.o maxmin.o main.cpp
	$(G) -c main.cpp -o $(M)

test.o: minmax.o maxmin.o
	$(G) -c test.cpp -o $(T)

minmax.o: heap.o MinMaxHeap.cpp
	$(G) -c MinMaxHeap.cpp -o $(MIN)

maxmin.o: heap.o MaxMinHeap.cpp
	$(G) -c MaxMinHeap.cpp -o $(MAX)

heap.o: Heap.cpp
	$(G) -c Heap.cpp -o $(H)

tar:
	cp $(shell find . -type f -name "*.*pp") \
		MakeFile data.txt \
		$(N)
	tar -cvf $(N).tar.gz $(N)

dir:
	rm -rf $(N)
	mkdir -p $(N)
	rm -rf build
	mkdir -p build

clean: dir
	rm $(N).tar.gz
