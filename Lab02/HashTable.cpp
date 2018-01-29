#include "HashTable.hpp"
#include <iostream>
using namespace std;


HashTable::HashTable(int mod)
{
    this->_mod = mod;
    this->_list = new LinkedList[mod];
}

HashTable::~HashTable() {
    delete this->_list;
}

/**
 * Calculate index to put value
 * @param value : value to hash
 * @return index of value
 */
int HashTable::Hash(int value) {
    return value % this->_mod;
}

/**
 * Inserts value into hash table
 * @param value : value to insert
 */
void HashTable::Insert(int value) {
    if (this->Find(value)) {
        cout << value << " already exists" << endl;
    } else {
        this->_list[this->Hash(value)].insert_front(value);
    }
}

/**
 * Print hash table
 */
void HashTable::Print() {
    for (int i = 0; i < this->_mod; i++) {
        cout << i << ": ";
        this->_list[i].print();
    }
}

/**
 * Checks if value is in hash table
 * @param value : value to find
 * @return returns true if value exists in table, false if not
 */
bool HashTable::Find(int value) {
    return (this->_list[this->Hash(value)].find(value) != nullptr);
}

/**
 * Deletes value from table
 * @param value : value to delete
 */
void HashTable::Delete(int value) {
    this->_list[this->Hash(value)].erase(value);
}