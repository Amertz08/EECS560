#ifndef EECS560_DHASHTABLE_HPP
#define EECS560_DHASHTABLE_HPP

#include "HashTable.hpp"

class DHashTable : public HashTable {
private:
    int _p;

public:
    DHashTable(int mod, int k, int p);

    int _func(int val, int i);
};


#endif //EECS560_DHASHTABLE_HPP
