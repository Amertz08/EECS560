#include <iostream>
#include "Bucket.hpp"
#include "HashTable.hpp"

HashTable::HashTable(int mod, int k) {
    this->_mod = mod;
    this->_k = k;
    this->_buckets = new Bucket[mod];
}

HashTable::~HashTable() {
    delete[] this->_buckets;
}

void HashTable::insert(int val) {
    if (this->find(val)) {
        std::cout << "Value already exists in table\n";
        return;
    }
    int hash = this->hash(val);
    if (hash == -1) {
        std::cout << "Could not find hash\n";
        return;
    }
    this->_buckets[hash].setVal(val);
}

void HashTable::remove(int val) {
    for (int i = 0; i < this->_mod; i++) {
        int hashVal = this->_hash(val, i);
        if (hashVal > this->_mod)
            hashVal = hashVal % this->_mod;
        if (this->_buckets[hashVal].getVal() == val) {
            this->_buckets[hashVal].remove();
            return;
        }
    }
    std::cout << "Could not find value\n";
}

int HashTable::hash(int val) {
    for (int i = 0; i < this->_k; i++) {
        int hashVal = this->_hash(val, i);
        if (hashVal > this->_mod)
            hashVal = hashVal % this->_mod;
        if (this->_buckets[hashVal].empty())
            return hashVal;
    }
    return -1;
}

int HashTable::_hash(int val, int i) {
    return (val % this->_mod + this->_func(val, i)) % this->_mod;
}

int HashTable::_func(int val, int i) { return 0; }


void HashTable::print() {
    for (int i = 0; i < this->_mod; i++) {
        if (!this->_buckets[i].empty()) {
            std::cout << "Bucket " << i << ": " << this->_buckets[i].getVal() << std::endl;
        }
    }
}

bool HashTable::find(int val) {
    for (int i = 0; i < this->_k; i++) {
        int hashVal = this->_hash(val, i);
        while (hashVal > this->_mod)
            hashVal -= this->_mod;
        if (this->_buckets[hashVal].getVal() == val) {
            return true;
        } else if (this->_buckets[hashVal].beenSet()) {
            return false;
        }
    }
    return false;
}

float HashTable::loadFactor() {
    float n = 0.0;
    for (int i = 0; i < this->_mod; i++) {
        if (!this->_buckets[i].empty())
            n += 1.0;
    }
    return n / (float)this->_mod;
}
