N=Mertz_Lab08
G=g++ -g -Wall -std=c++11
M=build/main.o
MIN=build/min.o
T=build/test.o


test: test.o
	$(G) -o build/test $(T) $(MIN)
	build/test data.txt

test.o: test.cpp min.o
	$(G) -c test.cpp -o $(T)

min.o: MinMaxHeap.cpp MinMaxHeap.hpp
	$(G) -c MinMaxHeap.cpp -o $(MIN)

dir:
	rm -rf build
	mkdir build