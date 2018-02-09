#include "HashTable.hpp"
#include <iostream>
using namespace std;


HashTable::HashTable(int mod)
{
    this->_mod = mod;
    this->_list = new LinkedList[mod];
}

HashTable::~HashTable() {
    delete[] this->_list;
}

int HashTable::Hash(int value) {
    return value % this->_mod;
}

void HashTable::Insert(int value) {
    if (this->Find(value)) {
        cout << value << " already exists" << endl;
    } else {
        this->_list[this->Hash(value)].insert_front(value);
    }
}

void HashTable::Print() {
    for (int i = 0; i < this->_mod; i++) {
        cout << i << ": ";
        this->_list[i].print();
    }
}

bool HashTable::Find(int value) {
    return (this->_list[this->Hash(value)].find(value) != nullptr);
}

void HashTable::Delete(int value) {
    this->_list[this->Hash(value)].erase(value);
}