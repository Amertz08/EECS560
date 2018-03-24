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

int MinHeap::_nthChildIndex(int i, int n) { return this->_k * i + n; }

int MinHeap::_nthChild(int i, int n) { return this->_heap[this->_nthChildIndex(i, n)]; }

void MinHeap::BuildHeap() {
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

int MinHeap::FindMin() {
    return this->_heap[this->_minIndex()];
}

int MinHeap::FindMax() {
    return this->_heap[this->_maxIndex()];
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
        auto max = this->_heap[maxIndex];

        // Look through children and find new max
        for (int i = maxIndex + 1; i < this->_k; i++) {
            if (this->_heap[i] > max) {
                max = this->_heap[i];
                maxIndex = i;
            }
        }

        // Shift remaining values left
        for (int i = maxIndex; i < this->_size; i++) {
            this->_heap[i] = this->_heap[i + 1];
        }
        this->_size--;
    }
}

void MinHeap::LevelOrder() {
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