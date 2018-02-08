#include <iostream>
#include "Bucket.hpp"
#include "QHashTable.hpp"
using namespace std;

QHashTable::QHashTable(int mod, int k) {
    this->_mod = mod;
    this->_k = k;
    this->_buckets = new Bucket[mod];
}

QHashTable::~QHashTable() {}

void QHashTable::insert(int val) {
    int hash = this->hash(val);
    if (hash == -1) {
        cout << "Could not find a hash\n";
        return;
    }
    this->_buckets[hash].setVal(val);
}

void QHashTable::remove(int val) {
    for (int i = 0; i < this->_mod; i++) {
        if (this->_buckets[i].getVal() == val) {
            this->_buckets[i].remove();
            break;
        }
    }
}

int QHashTable::hash(int val) {
    for (int i = 0; i < this->_k; i++) {
        int hashVal = this->_hash(val, i);
        while (hashVal > this->_mod)
            hashVal -= this->_mod;
        if (this->_buckets[hashVal].empty())
            return hashVal;
    }
    return -1;
}

int QHashTable::_hash(int val, int i) {
    return val % this->_mod + (i * i);
}

void QHashTable::print() {
    for (int i = 0; i < this->_mod; i++) {
        if (!this->_buckets[i].empty()) {
            cout << "Bucket " << i << ": " << this->_buckets[i].getVal() << endl;
        }
    }
}

bool QHashTable::find(int val) {
    for (int i = 0; i < this->_k; i++) {
        int hashVal = this->_hash(val, i);
        while (hashVal > this->_mod)
            hashVal -= this->_mod;
        if (this->_buckets[hashVal].getVal() == val) {
            return true;
        } else if (this->_buckets[hashVal].getVal() == -2) {
            return false;
        }
    }
    return false;
}