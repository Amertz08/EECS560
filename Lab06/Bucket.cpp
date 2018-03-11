#include "Bucket.hpp"

Bucket::Bucket() {
    this->_value = -2;
}

Bucket::~Bucket() = default;

int Bucket::getVal() {
    return this->_value;
}

void Bucket::setVal(int val) {
    this->_value = val;
}

void Bucket::remove() {
    this->_value = -1;
}

bool Bucket::empty() {
    return this->_value == -1 || this->_value == -2;
}

bool Bucket::beenSet() {
    return this->_value != -2;
}