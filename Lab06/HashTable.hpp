#ifndef EECS560_HASHTABLE_HPP
#define EECS560_HASHTABLE_HPP

#include <iostream>
#include "Bucket.hpp"
using namespace std;

class HashTable {
protected:
    int _mod;
private:
    int _k;
    Bucket* _buckets;

public:
    explicit HashTable(int mod);

    /**
     * Hash table
     * @param mod : modulo number
     * @param k : max tries
     */
    HashTable(int mod, int k);

    /**
     * Destructor
     */
    virtual ~HashTable();

    /**
     * Inserts value into table if possible
     * @param val
     */
    virtual void Insert(int val);

    /**
     * Remove value from table
     * @param val
     */
    virtual void Remove(int val);

    /**
     * Calculates hash for given value
     * @param val : value to hash
     * @return hash value or -1 if not able to find valid one
     */
    virtual int Hash(int val);

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
    virtual void Print();

    /**
     * Finds value in table
     * @param val : value to search for
     * @return true if found. false if not
     */
    virtual bool Find(int val);

    /**
     * Calculates the load factor
     * @return load factor
     */
    virtual float LoadFactor();
};

#endif //EECS560_HASHTABLE_HPP
