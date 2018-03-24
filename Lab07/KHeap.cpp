#include "KHeap.hpp"

KHeap::KHeap(int k) {
    this->_heap = new int[MAX_HEAP_SIZE]();
    this->_k = k;
    this->_size = 0;
}

KHeap::~KHeap() { delete[] this->_heap; }

