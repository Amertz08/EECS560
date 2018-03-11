#ifndef EECS560_QHASHTABLE_H
#define EECS560_QHASHTABLE_H

#include "Bucket.hpp"
#include "HashTable.hpp"

class QHashTable : public HashTable {

public:
    /**
     * Hash table that uses quadratic probing
     * @param mod
     */
    QHashTable(int mod, int k);

    /**
     * Hash f(i) function
     * @param i : loop index
     * @return : i^2
     */
    int _func(int val, int i) override;
};

#endif