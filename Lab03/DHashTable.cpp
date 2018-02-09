#include <iostream>
#include "Bucket.hpp"
#include "DHashTable.hpp"
using namespace std;

DHashTable::DHashTable(int mod, int p, int k) {
    this->_mod = mod;
    this->_p = p;
    this->_k = k;
    this->_buckets = new Bucket[mod];
}

DHashTable::~DHashTable() {
    delete[] this->_buckets;
}

void DHashTable::insert(int val) {
    int hash = this->hash(val);
    if (hash == -1) {
        cout << "Could not find hash\n";
        return;
    }
    this->_buckets[hash].setVal(val);
}

void DHashTable::remove(int val) {
    for (int i = 0; i < this->_mod; i++) {
        int hashVal = this->_hash(val, i);
        if (hashVal > this->_mod)
            hashVal = hashVal % this->_mod;
        if (this->_buckets[hashVal].getVal() == val) {
            this->_buckets[hashVal].remove();
            return;
        }
    }
    cout << "Could not find value\n";
}

void DHashTable::print() {
    for (int i = 0; i < this->_mod; i++) {
        if (!this->_buckets[i].empty()) {
            cout << "Bucket " << i << ": " << this->_buckets[i].getVal() << endl;
        }
    }
}

bool DHashTable::find(int val) {
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

int DHashTable::hash(int val) {
    for (int i = 0; i < this->_k; i++) {
        int hashVal = this->_hash(val, i);
        if (hashVal > this->_mod)
            hashVal = hashVal % this->_mod;
        if (this->_buckets[hashVal].empty())
            return hashVal;
    }
    return -1;
}

int DHashTable::_hash(int val, int i) {
    return (val + i * (this->_p - (val % this->_p))) % this->_mod;
}