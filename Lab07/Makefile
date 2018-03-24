G=g++ -g -Wall -std=c++11
NAME=Mertz_Lab07
M=build/main.o
K=build/kheap.o
MIN=build/min.o
MAX=build/max.o
OBJS=$(M) $(K) $(MIN) $(MAX)
BIN=build/Lab07

build: dir main.o
	$(G) $(OBJS) -o $(BIN)

test:
	$(BIN) data.txt

main.o: min.o max.o main.cpp
	$(G) -c main.cpp -o $(M)

max.o: kheap.o MaxHeap.cpp
	$(G) -c MaxHeap.cpp -o $(MAX)

min.o: kheap.o MinHeap.cpp
	$(G) -c MinHeap.cpp -o $(MIN)

kheap.o: KHeap.cpp
	$(G) -c KHeap.cpp -o $(K)

dir:
	rm -rf build
	mkdir build

clean: dir