#include "MinMaxHeap.hpp"

MinMaxHeap::MinMaxHeap() {
    this->_heap = new int[HEAP_SIZE]();
    this->_size = 0;
}

bool MinMaxHeap::_isMinNode(int index) { return this->_level(index) % 2 == 0; }

