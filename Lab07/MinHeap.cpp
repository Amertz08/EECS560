#include <iostream>
#include <math.h>
#include "MinHeap.hpp"

MinHeap::MinHeap() {
    this->_heap = new int[HEAP_SIZE]();
    this->_k = 5;
    this->_size = 0;
}

MinHeap::~MinHeap() { delete this->_heap; }

int MinHeap::_parentIndex(int index) { return int(floor((index - 1) / this->_k)); }

void MinHeap::_printNode(int index) {
    std::cout << "Node: " << this->_heap[index] << std::endl << "Children: ";
    for (int n = 1; n <= this->_k; n++) {
        std::cout << this->_nthChild(index, n) << " ";
    }
    std::cout << std::endl;
}

int MinHeap::_nthChild(int i, int n) { return this->_heap[this->_k * i + n]; }

void MinHeap::BuildHeap() {
    // Get most recent insertion index and value
    int targetIndex = this->_size - 1;

    // See if we are at root
    if (targetIndex == 0) {
        // Do nothing
        return;
    }

    // Continue
    this->_buildHeap(targetIndex);
}

void MinHeap::_buildHeap(int targetIndex) {
    auto targetVal = this->_heap[targetIndex];
    auto parentIndex = this->_parentIndex(targetIndex);
    auto parentVal =  this->_heap[parentIndex];

    // If parent is greater we need to swap
    if (parentVal > targetVal) {
        this->_heap[targetIndex] = parentVal;
        this->_heap[parentIndex] = targetVal;

        // If parent is root
        if (parentIndex == 0) {
            // Do nothing
            return;
        }

        // Continue
        this->_buildHeap(parentIndex);
    }
}

void MinHeap::Insert(int value) {
    // Put value at end
    this->Push(value);

    // Check up heap if swaps should happen
    this->_upHeap(this->_size - 1);
}

void MinHeap::Push(int value) {
    this->_heap[this->_size] = value;
    this->_size++;
}

void MinHeap::_upHeap(int index) {
    // Get value
    auto targetValue = this->_heap[index];

    // Get parent value
    auto parentIndex = this->_parentIndex(index);
    auto parentValue = this->_heap[parentIndex];

    // Check if we need to swap
    if (parentValue > targetValue) {
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

void MinHeap::Print() {
    for (int i = 0; i < this->_size; i++) {
        std::cout << this->_heap[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < this->_size; i++) {
        this->_printNode(i);
    }
}