#ifndef EECS560_HASHTABLE_HPP
#define EECS560_HASHTABLE_HPP

#include "LinkedList.hpp"

class HashTable {
private:
    LinkedList* _list;
    int _mod;
public:
    explicit HashTable(int mod);
    ~HashTable();

    /**
     * Inserts value into hash table
     * @param value : value to insert
     */
    void Insert(int value);

    /**
     * Deletes value from table
     * @param value : value to delete
     */
    void Delete(int value);

    /**
     * Print hash table
     */
    void Print();

    /**
     * Checks if value is in hash table
     * @param value : value to find
     * @return returns true if value exists in table, false if not
     */
    bool Find(int value);

    /**
     * Calculate index to put value
     * @param value : value to hash
     * @return index of value
     */
    int Hash(int value);
};

#endif //EECS560_HASHTABLE_HPP
