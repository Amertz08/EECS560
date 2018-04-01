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

void MinMax::Push(int value) {
    this->size++;
    this->heap[this->size] = value;
}

