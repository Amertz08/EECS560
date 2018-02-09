#ifndef EECS560_HASHTABLE_HPP
#define EECS560_HASHTABLE_HPP

#include <iostream>
#include "Bucket.hpp"
using namespace std;

class HashTable {
private:
    int _k, _mod;
    Bucket* _buckets;

public:
    /**
     * Hash table
     * @param mod : modulo number
     * @param k : max tries
     */
    HashTable(int mod, int k);

    /**
     * Destructor
     */
    ~HashTable();

    /**
     * Inserts value into table if possible
     * @param val
     */
    void insert(int val);

    /**
     * Remove value from table
     * @param val
     */
    void remove(int val);

    /**
     * Calculates hash for given value
     * @param val : value to hash
     * @return hash value or -1 if not able to find valid one
     */
    int hash(int val);

    /**
     * Helper function that calculates hash
     * @param val : value to hash
     * @return hash value
     */
    int _hash(int val, int i);

    /**
     * Function that is added to hash
     * @param i : index of loop
     * @return 0
     */
    virtual int _func(int val, int i);

    /**
     * Prints hash table
     */
    void print();

    /**
     * Finds value in table
     * @param val : value to search for
     * @return true if found. false if not
     */
    bool find(int val);
};

#endif //EECS560_HASHTABLE_HPP
