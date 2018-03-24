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

void KHeap::BuildHeap() {
    // Get most recent insertion index and value
    int targetIndex = this->_size - 1;

    // See if we are at root
    if (targetIndex == 0) {
        // Do nothing
        return;
    }

    // Get the last heap
    auto lastHeap = this->_parentIndex(targetIndex);

    // Down heap the rest
    for (int i = lastHeap; i >= 0; i--) {
        this->_downHeap(i);
    }
}