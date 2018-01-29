#ifndef EECS560_HASHTABLE_HPP
#define EECS560_HASHTABLE_HPP

#include "LinkedList.hpp"

class HashTable {
private:
    LinkedList* _list;
    int _mod;
public:
    HashTable(int mod);
    ~HashTable();
    void Insert(int value);
    void Delete(int value);
    void Print();
    bool Find(int value);
    int Hash(int value);
};

#endif //EECS560_HASHTABLE_HPP
