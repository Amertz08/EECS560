#include <iostream>
#include "Bucket.hpp"
#include "DHashTable.hpp"

DHashTable::DHashTable(int mod, int k, int p) : HashTable(mod, k) {
    this->_p = p;
}

int DHashTable::_func(int val, int i) {
    return i * (this->_p - (val % this->_p));
}
