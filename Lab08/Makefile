G=g++ -g -Wall -std=c++11
N=Mertz_Lab08
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
