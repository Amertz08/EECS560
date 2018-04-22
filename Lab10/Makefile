G=g++ -g -std=c++11 -Wall
N=build/node.o
H=build/heap.o
L=build/left.o
T=build/test.o
TEST=build/test

build: test

rtest:
	$(TEST)

test: dir test.o
	$(G) -o $(TEST) $(T) $(L) $(H) $(N)

test.o: left.o
	$(G) -c test.cpp -o $(T)

left.o: heap.o
	$(G) -c Leftist.cpp -o $(L)

heap.o: node.o
	$(G) -c Heap.cpp -o $(H)

node.o:
	$(G) -c Node.cpp -o $(N)

dir:
	rm -rf build
	mkdir build
