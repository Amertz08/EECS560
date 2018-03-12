#include <iostream>
#include "OpenHashTable.hpp"

OpenHashTable::OpenHashTable(int mod) : HashTable(mod) {
    this->_list = new LinkedList[mod];
}

// TODO: does not work
OpenHashTable::~OpenHashTable() {
    delete[] this->_list;
}

int OpenHashTable::Hash(int value) {
    return value % this->_mod;
}

void OpenHashTable::Insert(int value) {
    if (this->Find(value)) {
        return;
    } else {
        this->_list[this->Hash(value)].insert_front(value);
    }
}

void OpenHashTable::Print() {
    for (int i = 0; i < this->_mod; i++) {
        std::cout << i << ": ";
        this->_list[i].print();
    }
}

bool OpenHashTable::Find(int value) {
    return (this->_list[this->Hash(value)].find(value) != nullptr);
}

void OpenHashTable::Remove(int value) {
    this->_list[this->Hash(value)].erase(value);
}

float OpenHashTable::LoadFactor() {
    std::cout << "NOT IMPLEMENTED\n";
    return 0.00;
}