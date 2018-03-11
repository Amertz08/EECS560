#include <iostream>
#include <cstdlib>
#include <ctime>
#include "OpenHashTable.hpp"
#include "DHashTable.hpp"
#include "QHashTable.hpp"

/**
 * Returns random int from 1 <= max
 * @param max : highest value it can be
 * @return
 */
int generateNumber(int max) {
    return (std::rand() % max) + 1;
}

/**
 * Returns total insert time for the given number of insertions
 * @param table : table being inserted into
 * @param maxInsertions : number of insertions
 * @param maxRange : highest value of random number range
 * @return : total insert time
 */
int _testInsert(HashTable* table, int maxInsertions, int maxRange) {
    int insertTime = 0;
    for (int i = 0; i < maxInsertions; i++) {
        auto start = std::clock();
        table->Insert(generateNumber(maxRange));
        insertTime += std::clock() - start;
    }
    return insertTime;
}

/**
 * Finds average insert time over the number of test cases for the given amount of insertions
 * @param table : table to insert into
 * @param testCount : amount of times to test insert
 * @param maxInsertions : total number of insertions
 * @param maxRange : highest value of random number range
 * @return : average time for the amount of test cases
 */
int testInsert(HashTable* table, int testCount, int maxInsertions, int maxRange) {
    int totalTime = 0;
    for (int i = 0; i < testCount; i++) {
        std::srand((unsigned)i);
        totalTime += _testInsert(table, maxInsertions, maxRange);
    }
    return totalTime / testCount;
}


int main(int argc, char* argv[]) {
    const int m = 1000003;
    const int p = 997;
    const int k = 20;
    const int maxInsertions = 100000;
    const int maxRange = 5000000;

    OpenHashTable openTable(m);
    QHashTable  qTable(m, k);
    DHashTable dTable(m, k, p);


    auto val = testInsert(&qTable, 5, maxInsertions, maxRange);
    std::cout << val << " CPU clocks\n";
    val = testInsert(&dTable, 5, maxInsertions, maxRange);
    std::cout << val << " CPU clocks\n";
    val = testInsert(&openTable, 5, maxInsertions, maxRange);
    std::cout << val << " CPU clocks\n";

}