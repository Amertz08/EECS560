#include <iostream>
#include <string>

#include <math.h>

#include "MinMax.hpp"

MinMax::MinMax() {
    this->heap = new int[MAX_SIZE];
    this->size = 0;
}

MinMax::~MinMax() { delete this->heap; }

bool MinMax::isMinNode(int i) { return (int)floor(log(i)) % 2 == 0; }

int MinMax::parentIndex(int i) { return (int)floor(i / 2); }

int MinMax::parent(int i) { return this->heap[this->parentIndex(i)]; }

int MinMax::leftChildIndex(int i) { return 2 * i; }

int MinMax::rightChildIndex(int i) { return 2 * i + 1; }

int MinMax::leftChild(int i) { return this->heap[this->leftChildIndex(i)]; }

int MinMax::rightChild(int i) { return this->heap[this->rightChildIndex(i)]; }

void MinMax::printNode(int i) {
    auto val = this->heap[i];
    auto left = this->leftChild(i);
    auto right = this->rightChild(i);
    std::string type = this->isMinNode(i) ? "MIN" : "MAX";

    std::cout << "Node: " << val << " type: " << type << std::endl
              << "Left: " << left << " Right: " << right
              << std::endl;
}

void MinMax::Push(int value) {
    this->size++;
    this->heap[this->size] = value;
}

void MinMax::Print() {
    for (int i = ROOT; i < this->size; i++)
        this->printNode(i);
}

