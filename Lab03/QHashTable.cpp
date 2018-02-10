#include <iostream>
#include "QHashTable.hpp"

QHashTable::QHashTable(int mod, int k) : HashTable(mod, k) {}

int QHashTable::_func(int val, int i) { return i * i; }
