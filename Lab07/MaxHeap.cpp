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
        if (val < min) {
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
        auto minIndex = this->_minIndex();

        /*
         * Min value in max heap would have to be in a leaf.
         * Because of this we can simply shift all values after
         * it to the left.
         */
        for (int i = minIndex; i < this->_size; i++) {
            this->_heap[i] = this->_heap[i + 1];
        }
        this->_size--;
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
        auto maxIndex = this->_maxIndex();
        auto max = this->_heap[maxIndex];

        // Look through children and find new max
        for (int i = maxIndex + 1; i < this->_k; i++) {
            if (this->_heap[i] > max) {
                max = this->_heap[i];
                maxIndex = i;
            }
        }

        // Reassign max to root
        this->_heap[0] = max;

        // Shift remaining values left
        for (int i = maxIndex; i < this->_size; i++) {
            this->_heap[i] = this->_heap[i + 1];
        }
        this->_size--;
    }
}
