#include <iostream>
#include <math.h>

#include "KHeap.hpp"


KHeap::~KHeap() = default;

int KHeap::_parentIndex(int index) { return int(floor((index - 1) / this->_k)); }

int KHeap::_nthChildIndex(int i, int n) {
    auto val = this->_k * i + n;
    if (val > MAX_HEAP_SIZE) {
        return -1;
    }
    return val;
}

int KHeap::_nthChild(int i, int n) {
    auto index = this->_nthChildIndex(i, n);
    if (index == -1)
        return -1;
    return this->_heap[index];
}

void KHeap::_upHeap(int index) {
    // Get value
    auto targetValue = this->_heap[index];

    // Get parent value
    auto parentIndex = this->_parentIndex(index);
    auto parentValue = this->_heap[parentIndex];

    // Check if we need to swap
    if (this->_compare(parentValue, targetValue)) {
        // Swap
        this->_heap[parentIndex] = targetValue;
        this->_heap[index] = parentValue;

        // If parent is root we don't continue
        if (!parentIndex) {
            return;
        }
        this->_upHeap(parentIndex);
    }
}

void KHeap::_printNode(int index) {
    std::cout << "Node: " << this->_heap[index] << std::endl << "Children: ";
    for (int n = 1; n <= this->_k; n++) {
        auto childVal = this->_nthChild(index, n);
        if (childVal == -1) {
            std::cout << "0 ";
        } else {
            std::cout << this->_nthChild(index, n) << " ";
        }
    }
    std::cout << std::endl;
}


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

void KHeap::Insert(int value) {
    // Put value at end
    this->Push(value);

    // Check up heap if swaps should happen
    this->_upHeap(this->_size - 1);
}

void KHeap::Push(int value) {
    this->_heap[this->_size] = value;
    this->_size++;
}

void KHeap::Print() {
    for (int i = 0; i < this->_size; i++) {
        std::cout << this->_heap[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < this->_size; i++) {
        this->_printNode(i);
    }
}

int KHeap::FindMin() {
    return this->_heap[this->_minIndex()];
}

int KHeap::FindMax() {
    return this->_heap[this->_maxIndex()];
}

void KHeap::LevelOrder() {
    if (!this->_size) {
        std::cout << "Empty Heap\n";
    } else {
        int levels = 1;

        while (pow(this->_k, levels) < this->_size)
            levels++;

        int start = 0;
        for (int i = 0; i <= levels; i++) {
            auto end = (int)pow(this->_k, i);
            if (i != 0)
                end++;
            for (int j = start; j < end; j++) {
                std::cout << this->_heap[j] << " ";
                if (j % this->_k == 0 && i != 0 && j != end - 1) {
                    std::cout << "- ";
                }
            }
            std::cout << std::endl;
            start = end;

        }
    }
}
