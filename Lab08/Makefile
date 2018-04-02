G=g++ -g -Wall -std=c++11
TBIN=build/test
T=build/test.o
MIN=build/minmax.o
MAX=build/maxmin.o

runtest:
	$(TBIN)

test: test.o
	$(G) -o $(TBIN) $(T) $(MIN) $(MAX)

test.o: minmax.o maxmin.o
	$(G) -c test.cpp -o $(T)

minmax.o: MinMaxHeap.cpp
	$(G) -c MinMaxHeap.cpp -o $(MIN)

maxmin.o: MaxMinHeap.cpp
	$(G) -c MaxMinHeap.cpp -o $(MAX)

dir:
	rm -rf build
	mkdir -p build
