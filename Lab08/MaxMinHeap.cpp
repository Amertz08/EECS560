
#include "MaxMinHeap.hpp"

MaxMinHeap::MaxMinHeap() {
    this->_heap = new int[HEAP_SIZE]();
    this->_size = 0;
}

bool MaxMinHeap::_isMinNode(int index) { return this->_level(index) % 2 != 0; }
