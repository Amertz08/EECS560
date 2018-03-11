#ifndef EECS560_OPENHASHTABLE_HPP
#define EECS560_OPENHASHTABLE_HPP

#include "HashTable.hpp"
#include "LinkedList.hpp"

class OpenHashTable : public HashTable {
private:
    LinkedList* _list;
public:
    explicit OpenHashTable(int mod);

    ~OpenHashTable() override;
    void Insert(int value) override;
    void Remove(int value) override;
    void Print() override;
    bool Find(int value) override;
    int Hash(int value) override;
    float LoadFactor() override;
};


#endif //EECS560_OPENHASHTABLE_HPP
