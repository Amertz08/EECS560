#include <math.h>

#include "KHeap.hpp"

KHeap::KHeap(int k) {
    this->_heap = new int[MAX_HEAP_SIZE]();
    this->_k = k;
    this->_size = 0;
}

KHeap::~KHeap() { delete[] this->_heap; }

int KHeap::_parentIndex(int index) { return int(floor((index - 1) / this->_k)); }

int KHeap::_nthChildIndex(int i, int n) { return this->_k * i + n; }

int KHeap::_nthChild(int i, int n) { return this->_heap[this->_nthChildIndex(i, n)]; }