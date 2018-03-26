#include <iostream>
#include <math.h>

#include "MinMaxHeap.hpp"

MinMaxHeap::MinMaxHeap() {
    this->_heap = new int[HEAP_SIZE]();
    this->_size = 0;
}

MinMaxHeap::~MinMaxHeap() { delete[] this->_heap; }

void MinMaxHeap::Push(int val) {
    this->_size++;
    this->_heap[this->_size] = val;
}

void MinMaxHeap::Insert(int val) {
    this->Push(val);
    this->_upHeap(this->_size);
}

void MinMaxHeap::_upHeap(int index) {
    if (index == 1)
        return;

    auto parentIndex = this->_parentIndex(index);


    if (this->_shouldSwap(parentIndex, index)) {
        // Swap values
        auto targetValue = this->_heap[index];
        auto pValue = this->_heap[parentIndex];
        this->_heap[parentIndex] = targetValue;
        this->_heap[index] = pValue;

        // Continue
        this->_upHeap(parentIndex);
    }
}

bool MinMaxHeap::_isMinNode(int index) {
    return (int)floor(log(index)) % 2 == 0;
}

int MinMaxHeap::_parentIndex(int index) { return (int)floor(index / 2); }

bool MinMaxHeap::_shouldSwap(int parentIndex, int index) {
    auto pValue = this->_heap[parentIndex];
    auto target = this->_heap[index];
    if (this->_isMinNode(parentIndex)) {
        return target < pValue;
    } else {
        return target > pValue;
    }
}

void MinMaxHeap::Print() {
    std::cout << "Printing\n";
    for (int i = 1; i < this->_size + 1; i++)
        this->_printNode(i);
}

void MinMaxHeap::_printNode(int index) {
    std::cout << "Node: "
              << this->_heap[index]
              << std::endl
              << "left: "
              << this->_heap[this->_leftChild(index)]
              << " right: "
              << this->_heap[this->_rightChild(index)]
              << std::endl;
}

int MinMaxHeap::_leftChild(int index) { return 2 * index; }

int MinMaxHeap::_rightChild(int index) { return (2 * index) + 1; }

void MinMaxHeap::_downHeap(int index) {
    if (index > this->_size)
        return;

    if (this->_isMinNode(index)) {
        auto minIndex = this->_findMin(index);
        auto min = this->_heap[minIndex];
        auto current = this->_heap[index];

        // Swap
        if (min != current) {
            this->_heap[minIndex] = current;
            this->_heap[index] = min;
        }
        this->_downHeap(index + 1);
    } else {
        auto maxIndex = this->_findMax(index);
        auto max = this->_heap[maxIndex];
        auto current = this->_heap[index];

        // Swap
        if (max != current) {
            this->_heap[maxIndex] = current;
            this->_heap[index] = max;
        }
        this->_downHeap(index + 1);
    }
}

int MinMaxHeap::_findMin(int index) {
    auto min = this->_heap[index];
    auto minIndex = index;

    for (int i = index + 1; i <= this->_size; i++) {
        if (this->_heap[i] < min) {
            min = this->_heap[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int MinMaxHeap::_findMax(int index) {
    auto max = this->_heap[index];
    auto maxIndex = index;

    for (int i = index + 1; i <= this->_size; i++) {
        if (this->_heap[i] > max) {
            max = this->_heap[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void MinMaxHeap::BuildHeap() {
    if (this->_size == 1)
        return;

    auto lastHeap = this->_parentIndex(this->_size);

    for (int i = lastHeap; i > 0; i++)
        this->_downHeap(i);
}