#ifndef EECS560_QHASHTABLE_H
#define EECS560_QHASHTABLE_H

#include "Bucket.hpp"

class QHashTable {
private:
    Bucket* _buckets;
    int _k;
    int _mod;

public:
    /**
     * Hash table that uses quadratic probing
     * @param mod
     */
    explicit QHashTable(int mod, int k);

    /**
     * Deconstructor
     */
    ~QHashTable();

    /**
     * Insert value to table
     * @param val
     */
    void insert(int val);

    /**
     * Removes value from table
     * @param val
     */
    void remove(int val);

    /**
     * Prints non empty buckets
     */
    void print();

    /**
     * Finds value in table
     * @param val : value to search for
     * @return true if found
     */
    bool find(int val);

    /**
     * Finds hash for value
     * @param val : value to hash
     * @return Hash of value
     */
    int hash(int val);
};

#endif