#include <iostream>
#include "MaxHeap.hpp"

MaxHeap::MaxHeap(int k) {
    this->_heap = new int[MAX_HEAP_SIZE]();
    this->_k = k;
    this->_size = 0;
}

MaxHeap::~MaxHeap() { delete[] this->_heap; }

bool MaxHeap::_compare(int parent, int child) { return parent < child; }

void MaxHeap::_downHeap(int index) {
    auto targetValue = this->_heap[index];
    auto max = targetValue;
    auto maxIndex = index;

    for (int n = 1; n <= this->_k; n++) {
        auto childValue = this->_nthChild(index, n);
        if (childValue > max && childValue != 0) {
            max = childValue;
            maxIndex = this->_nthChildIndex(index, n);
        }
    }

    // If one of the children is greater than the target value swap
    if (max != targetValue) {
        this->_heap[index] = max;
        this->_heap[maxIndex] = targetValue;
        // Continue down child node
        this->_downHeap(maxIndex);
    }
}

int MaxHeap::_minIndex() {
    int minIndex = 0;
    int min = this->_heap[minIndex];

    for (int i = 0; i < this->_size; i++) {
        auto val = this->_heap[i];
        if (val < min && val != 0) {
            min = val;
            minIndex = i;
        }
    }
    return minIndex;
}

int MaxHeap::_maxIndex() {
    return 0;
}

void MaxHeap::DeleteMin() {
    if (this->_size == 0) {
        std::cout << "Empty heap\n";
        return;
    } else if (this->_size == 1) {
        this->_heap[0] = 0;
        this->_size--;
        return;
    } else {
        // Root has children

        // Get last value and overwrite min
        auto minIndex = this->_minIndex();
        auto lastVal = this->_heap[this->_size - 1];
        this->_heap[this->_size - 1] = 0;
        this->_heap[minIndex] = lastVal;
        this->_size--;
        this->_upHeap(minIndex);
    }
}

void MaxHeap::DeleteMax() {
    if (this->_size == 0) {
        std::cout << "Empty heap\n";
        return;
    } else if (this->_size == 1) {
        this->_heap[0] = 0;
        this->_size--;
        return;
    } else {
        // Root has children

        // Get last value and overwrite max
        auto lastVal = this->_heap[this->_size - 1];
        this->_heap[this->_size - 1] = 0;
        this->_heap[0] = lastVal;
        this->_size--;
        this->_downHeap(0);
    }
}
