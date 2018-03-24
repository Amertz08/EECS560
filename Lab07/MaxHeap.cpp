#include <iostream>
#include <math.h>
#include "MaxHeap.hpp"

MaxHeap::MaxHeap() {
    this->_heap = new int[HEAP_SIZE]();
    this->_k = 5;
    this->_size = 0;
}

MaxHeap::~MaxHeap() { delete this->_heap; }

bool MaxHeap::_compare(int parent, int child) {
    return parent < child;
}

int MaxHeap::_parentIndex(int index) { return int(floor((index - 1) / this->_k)); }

void MaxHeap::_printNode(int index) {
    std::cout << "Node: " << this->_heap[index] << std::endl << "Children: ";
    for (int n = 1; n <= this->_k; n++) {
        std::cout << this->_nthChild(index, n) << " ";
    }
    std::cout << std::endl;
}

int MaxHeap::_nthChildIndex(int i, int n) { return this->_k * i + n; }

int MaxHeap::_nthChild(int i, int n) { return this->_heap[this->_nthChildIndex(i, n)]; }

void MaxHeap::BuildHeap() {
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

void MaxHeap::Insert(int value) {
    // Put value at end
    this->Push(value);

    // Check up heap if swaps should happen
    this->_upHeap(this->_size - 1);
}

void MaxHeap::Push(int value) {
    this->_heap[this->_size] = value;
    this->_size++;
}

void MaxHeap::_upHeap(int index) {
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

void MaxHeap::Print() {
    for (int i = 0; i < this->_size; i++) {
        std::cout << this->_heap[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < this->_size; i++) {
        this->_printNode(i);
    }
}

int MaxHeap::_minIndex() {
    int minIndex = 0;
    int min = this->_heap[minIndex];

    for (int i = 0; i < this->_size - 1; i++) {
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

int MaxHeap::FindMin() {
    return this->_heap[this->_minIndex()];
}

int MaxHeap::FindMax() {
    return this->_heap[this->_maxIndex()];
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
            std::cout << "index: " << i << std::endl;
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

void MaxHeap::LevelOrder() {
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