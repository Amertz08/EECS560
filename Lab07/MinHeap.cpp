#include <iostream>
#include "MinHeap.hpp"

bool MinHeap::_compare(int parent, int child) { return parent > child; }

void MinHeap::_downHeap(int index) {
    auto targetValue = this->_heap[index];
    auto min = targetValue;
    auto minIndex = index;

    for (int n = 1; n <= this->_k; n++) {
        auto childValue = this->_nthChild(index, n);
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

    for (int i = 0; i < this->_size - 1; i++) {
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
        auto minIndex = this->_minIndex() + 1;
        auto min = this->_heap[minIndex];

        // Look through children and find new min
        for (int i = minIndex + 1; i < this->_k; i++) {
            if (this->_heap[i] < min) {
                min = this->_heap[i];
                minIndex = i;
            }
        }

        // Reassign root to new min
        this->_heap[0] = min;

        // Shift remaining values left
        for (int i = minIndex; i < this->_size; i++) {
            this->_heap[i] = this->_heap[i + 1];
        }
        this->_size--;
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
        auto maxIndex = this->_maxIndex();

        /*
         * Max value in Min heap would have to be in a leaf.
         * Because of this we can simply shift all values after
         * it to the left.
         */
        for (int i = maxIndex; i < this->_size; i++) {
            this->_heap[i] = this->_heap[i + 1];
        }
        this->_size--;
    }
}
