G=g++ -g -Wall -std=c++11
NAME=Mertz_Lab07
M=build/main.o
T=build/test.o
K=build/kheap.o
MIN=build/min.o
MAX=build/max.o
OBJS=$(K) $(MIN) $(MAX)
BIN=build/Lab07
TEST=build/Lab07Test
ARCH=$(NAME).tar.gz

build: dir main.o test.o
	$(G) $(M) $(OBJS) -o $(BIN)
	$(G) $(T) $(OBJS) -o $(TEST)

run:
	$(BIN) data.txt

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(BIN) data.txt

test:
	$(TEST) data.txt

main.o: min.o max.o main.cpp
	$(G) -c main.cpp -o $(M)

test.o: min.o max.o test.cpp
	$(G) -c test.cpp -o $(T)

max.o: kheap.o MaxHeap.cpp
	$(G) -c MaxHeap.cpp -o $(MAX)

min.o: kheap.o MinHeap.cpp
	$(G) -c MinHeap.cpp -o $(MIN)

kheap.o: KHeap.cpp
	$(G) -c KHeap.cpp -o $(K)

tar: dir
	cp $(shell find . -type f -name "*.*pp") \
		Makefile data.txt README.txt \
		$(NAME)
	tar -cvf $(ARCH) $(NAME)

dir:
	rm -rf $(NAME)
	mkdir $(NAME)
	rm -rf build
	mkdir build

clean: dir
	rm $(ARCH)