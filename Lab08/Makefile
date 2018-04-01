G=g++ -g -Wall -std=c++11
TBIN=build/test
T=build/test.o
MIN=build/minmax.o

runtest:
	$(TBIN)

test: test.o
	$(G) -o $(TBIN) $(T) $(MIN)

test.o: minmax.o
	$(G) -c test.cpp -o $(T)

minmax.o: MinMax.cpp
	$(G) -c MinMax.cpp -o $(MIN)

dir:
	rm -rf build
	mkdir -p build
