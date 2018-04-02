#include <iostream>
#include <math.h>

#include "Heap.hpp"

Heap::Heap() {
    this->_heap = new int[HEAP_SIZE]();
    this->_size = 0;
}

Heap::~Heap() { delete[] this->_heap; }

void Heap::Push(int val) {
    this->_size++;
    this->_heap[this->_size] = val;
}

void Heap::Insert(int val) {
    this->Push(val);
    this->_upHeap(this->_size);
}

void Heap::_upHeap(int index) {
    if (index == ROOT)
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

int Heap::_level(int index) { return (int)floor(log2(index)); }

int Heap::_parentIndex(int index) { return (int)floor(index / 2); }

bool Heap::_shouldSwap(int parentIndex, int index) {
    auto pValue = this->_heap[parentIndex];
    auto target = this->_heap[index];
    if (this->_isMinNode(parentIndex)) {
        return target < pValue;
    } else {
        return target > pValue;
    }
}

void Heap::Print() {
    std::cout << "Printing\n";
    for (int i = ROOT; i < this->_size + 1; i++)
        this->_printNode(i);
}

void Heap::_printNode(int index) {
    std::string type = this->_isMinNode(index) ? "MIN" : "MAX";
    std::cout << "Node: "
              << this->_heap[index]
              << " type: "
              << type
              << std::endl
              << "left: "
              << this->_leftChild(index)
              << " right: "
              << this->_rightChild(index)
              << std::endl;
}

bool Heap::_isLeaf(int index) { return this->_leftChild(index) == 0 && this->_rightChild(index) == 0; }

int Heap::_leftChildIndex(int index) { return 2 * index; }

int Heap::_rightChildIndex(int index) { return (2 * index) + 1; }

int Heap::_leftChild(int index) { return this->_heap[this->_leftChildIndex(index)]; }

int Heap::_rightChild(int index) { return this->_heap[this->_rightChildIndex(index)]; }

void Heap::_downHeap(int index) {
    if (this->_isLeaf(index) || this->_heap[index] == 0) {
        return;
    }

    if (this->_isMinNode(index)) {
        auto min = this->_heap[index];
        auto leftMinIndex = this->_findMinIndex(index);
        auto rightMinIndex = this->_findMinIndex(index);
        auto left = this->_heap[leftMinIndex];
        auto right = this->_heap[rightMinIndex];

        if (left < right) {
            if (left < min) {
                this->_heap[index] = left;
                this->_heap[leftMinIndex] = min;
            }
        } else {
            if (right < min) {
                this->_heap[index] = right;
                this->_heap[rightMinIndex] = min;
            }
        }
    } else {
        auto max = this->_heap[index];
        auto leftMaxIndex = this->_findMaxIndex(index);
        auto rightMaxIndex = this->_findMaxIndex(index);
        auto left = this->_heap[leftMaxIndex];
        auto right = this->_heap[rightMaxIndex];

        if (left > right) {
            if (left > max) {
                this->_heap[index] = left;
                this->_heap[leftMaxIndex] = max;
            }
        } else {
            if (right > max) {
                this->_heap[index] = right;
                this->_heap[rightMaxIndex] = max;
            }
        }
    }
    this->_downHeap(this->_leftChildIndex(index));
    this->_downHeap(this->_rightChildIndex(index));
}

int Heap::_findMinIndexHelper(int index, int minIndex) {
    // See if current node is less than current min
    auto current = this->_heap[index];
    auto min = this->_heap[minIndex];
#if DEBUG
    std::cout << "Before swap current: " << current << " min: " << min << std::endl;
#endif
    if (current < min && current != 0) {
        minIndex = index;
        min = current;
    }
#if DEBUG
    std::cout << "After swap current: " << current << " min: " << min << std::endl;
#endif

    if (!this->_isLeaf(index)) {
        minIndex = this->_findMinIndexHelper(this->_leftChildIndex(index), minIndex);
        minIndex = this->_findMinIndexHelper(this->_rightChildIndex(index), minIndex);
    }
    return minIndex;
}

int Heap::_findMinIndex(int index) { return this->_findMinIndexHelper(index, index); }

int Heap::_findMaxIndexHelper(int index, int maxIndex) {
    // See if current node is greater than current min
    auto current = this->_heap[index];
    auto max = this->_heap[maxIndex];
#if DEBUG
    std::cout << "Before swap current: " << current << " max: " << max << std::endl;
#endif
    if (current > max) {
        maxIndex = index;
        max = current;
    }
#if DEBUG
    std::cout << "After swap current: " << current << " max: " << max << std::endl;
#endif

    if (!this->_isLeaf(index)) {
        maxIndex = this->_findMaxIndexHelper(this->_leftChildIndex(index), maxIndex);
        maxIndex = this->_findMaxIndexHelper(this->_rightChildIndex(index), maxIndex);
    }
    return maxIndex;
}

int Heap::_findMaxIndex(int index) { return this->_findMaxIndexHelper(index, index); }

int Heap::_findMin(int index) { return this->_heap[this->_findMinIndex(index)]; }

int Heap::_findMax(int index) { return this->_heap[this->_findMaxIndex(index)]; }

void Heap::BuildHeap() {
    if (this->_size == ROOT)
        return;

    auto lastHeap = this->_size;

#if DEBUG
    std::cout << "lastHeap: " << lastHeap << " value: " << this->_heap[lastHeap] << std::endl;
#endif

    for (int i = lastHeap; i >= ROOT; i--)
        this->_downHeap(i);
}

void Heap::LevelOrder() {
    auto totalLevels = this->_level(this->_size);
#if DEBUG
    std::cout << "totalLevels: " << totalLevels << std::endl;
#endif

    int start = ROOT;
    for (int i = 0; i <= totalLevels; i++) {
        auto end = start + (int)pow(2, i);
        std::cout << "Level " << i << ": ";
#if DEBUG
        std::cout << "i: " << i << " start: " << start << " end: " << end << std::endl;
#endif
        for (int j = start; j < end; j++) {
            std::cout << this->_heap[j] << " ";
        }
        std::cout << std::endl;
        start = end;
    }
}

int Heap::FindMin() { return this->_findMin(ROOT); }

int Heap::FindMax() { return this->_findMax(ROOT); }

void Heap::DeleteMin() {
    auto minIndex = this->_findMinIndex(ROOT);

    auto mostRecentIndex = this->_size;

    this->_heap[minIndex] = this->_heap[mostRecentIndex];
    this->_heap[mostRecentIndex] = 0;
    this->_size--;
    this->_downHeap(minIndex);
}

void Heap::DeleteMax() {
    auto maxIndex = this->_findMaxIndex(ROOT);

    auto mostRecentIndex = this->_size;

    this->_heap[maxIndex] = this->_heap[mostRecentIndex];
    this->_heap[mostRecentIndex] = 0;
    this->_size--;
    this->_downHeap(maxIndex);
}
