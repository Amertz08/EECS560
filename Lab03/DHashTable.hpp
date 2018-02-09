#ifndef EECS560_DHASHTABLE_HPP
#define EECS560_DHASHTABLE_HPP


class DHashTable {
private:
    int _p, _k, _mod;
    Bucket* _buckets;

public:
    DHashTable(int mod, int p, int k);
    ~DHashTable();

    /**
     * Hash function for given value
     * @param val : value to hash
     * @return hash index or -1 if it cannot be found
     */
    int hash(int val);

    /**
     * Calculates the actual hash value
     * @param val : value to hash
     * @param i : index
     * @return Hash value
     */
    int _hash(int val, int i);

    /**
     * Inserts value into Hash table
     * @param val : value to insert
     */
    void insert(int val);

    /**
     * Removes value from hash table
     * @param val : value to remove
     */
    void remove(int val);

    /**
     * Prints all non empty buckets in Hash Table
     */
    void print();

    /**
     * Looks for value in table
     * @param val : value to search for
     * @return returns true if found false if not
     */
    bool find(int val);
};


#endif //EECS560_DHASHTABLE_HPP
