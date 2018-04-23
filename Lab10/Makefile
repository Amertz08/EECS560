G=g++ -g -std=c++11 -Wall
NAME=Mertz_Lab10
N=build/node.o
H=build/heap.o
DH=build/dheap.o
L=build/left.o
S=build/skew.o
T=build/test.o
M=build/main.o
TEST=build/TestLab10
BIN=build/Lab10

build: dir test main

# Run main.cpp binary
rmain:
	$(BIN) data.txt

# Run test.cpp binary
rtest:
	$(TEST)

main: main.o
	$(G) -o $(BIN) $(M) $(L) $(S) $(H) $(N)

main.o: left.o skew.o
	$(G) -c main.cpp -o $(M)

test: test.o
	$(G) -o $(TEST) $(T) $(L) $(S) $(DH) $(N)

test.o: left.o skew.o
	$(G) -c test.cpp -o $(T)

skew.o: heap.o dheap.o
	$(G) -c Skew.cpp -o $(S)

left.o: heap.o dheap.o
	$(G) -c Leftist.cpp -o $(L)

# Build normal heap class
heap.o: node.o
	$(G) -c Heap.cpp -o $(H)

# Build with DEBUG preprocessor define
dheap.o: node.o
	$(G) -DDEBUG=1 -c Heap.cpp -o $(DH)

node.o:
	$(G) -c Node.cpp -o $(N)

tardir:
	rm -rf $(NAME)
	mkdir $(NAME)

tar: tardir
	cp -f $(shell find . -type f -name "*.*pp") \
		Makefile \
		$(NAME)
	tar -cvf $(NAME).tar.gz $(NAME)

dir:
	rm -rf build
	mkdir build

clean: dir tardir
	rm -rf $(NAME).tar.gz