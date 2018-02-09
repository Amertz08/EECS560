#ifndef EECS560_DHASHTABLE_HPP
#define EECS560_DHASHTABLE_HPP

#include "HashTable.hpp"

class DHashTable : public HashTable {
private:
    int _p;

public:
    /**
     * Constructor
     * @param mod : modulo
     * @param k : max hash tries
     * @param p : p value
     */
    DHashTable(int mod, int k, int p);

    /**
     * Function added onto H(val)
     * @param val : value to hash
     * @param i : loop index
     * @return i * (p - val % p)
     */
    int _func(int val, int i);
};


#endif //EECS560_DHASHTABLE_HPP
