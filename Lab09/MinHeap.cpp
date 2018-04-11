#include <iostream>
#include "MinHeap.hpp"

MinHeap::MinHeap(int k) {
    this->_heap = new int[MAX_HEAP_SIZE]();
    this->_k = k;
    this->_size = 0;
}

MinHeap::~MinHeap() { delete[] this->_heap; }

bool MinHeap::_compare(int parent, int child) { return parent > child; }

void MinHeap::_downHeap(int index) {
    auto targetValue = this->_heap[index];
    auto min = targetValue;
    auto minIndex = index;

    for (int n = 1; n <= this->_k; n++) {
        auto childValue = this->_nthChild(index, n);
        if (childValue == -1)
            break;
        if (childValue < min && childValue != 0) {
            min = childValue;
            minIndex = this->_nthChildIndex(index, n);
        }
    }

    // If one of the children is less than the target value swap
    if (min != targetValue) {
        this->_heap[index] = min;
        this->_heap[minIndex] = targetValue;
        // Continue down child node
        this->_downHeap(minIndex);
    }
}

int MinHeap::_minIndex() {
    return 0;
}

int MinHeap::_maxIndex() {
    int maxIndex = 0;
    int max = this->_heap[maxIndex];

    for (int i = 0; i < this->_size; i++) {
        auto val = this->_heap[i];
        if (val > max) {
            max = val;
            maxIndex = i;
        }
    }
    return maxIndex;
}

void MinHeap::DeleteMin() {
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
        this->_downHeap(minIndex);
    }
}

void MinHeap::DeleteMax() {
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
        auto maxIndex = this->_maxIndex();
        auto lastValue = this->_heap[this->_size - 1];
        this->_heap[this->_size - 1] = 0;
        this->_heap[maxIndex] = lastValue;
        this->_size--;
        this->_upHeap(maxIndex);
    }
}
