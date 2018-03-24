G=g++ -g -Wall -std=c++11
NAME=Mertz_Lab07
M=build/main.o
MIN=build/min.o
MAX=build/max.o
BIN=build/Lab07

build: dir main.o
	$(G) $(M) $(MIN) -o $(BIN)

test:
	$(BIN) data.txt

main.o: min.o max.o
	$(G) -c main.cpp -o $(M)

max.o:
	$(G) -c MaxHeap.cpp -o $(MAX)

min.o:
	$(G) -c MinHeap.cpp -o $(MIN)

dir:
	rm -rf build
	mkdir build

clean: dir