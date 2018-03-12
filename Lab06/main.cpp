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

int* testFind(HashTable* table, int maxRange) {
    auto totalTime = new int[2]();
    int tests = 10000;
    std::srand((unsigned)std::time(nullptr)); // Random seed
    for (int i = 0; i < tests; i++) {
        auto searchVal = generateNumber(maxRange);
        auto start = std::clock();
        auto found = table->Find(searchVal);
        auto elapsed = std::clock() - start;
        if (found) {
            totalTime[0] += elapsed;
        } else {
            totalTime[1] += elapsed;
        }
    }
    return totalTime;
}

void printRow(int **row, int n) {
    std::string rowType;

    if (n == 0) {
        rowType = "Build ";
    } else if (n == 1) {
        rowType = "Found ";
    } else {
        rowType = "Not Found ";
    }

    std::cout << rowType;
    for (int j = 0; j < 5; j++) {
        std::cout << row[j][n] << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char* argv[]) {
    const int m = 1000003;
    const int p = 997;
    const int k = 20;
    int maxInsertions[5] = {100000, 200000, 300000, 400000, 500000};
    const int maxRange = 5000000;

    // Results array for each type of table
    int*** results = new int**[3];
    for (int i = 0; i < 3; i++) {
        // For each table type create a results array
        results[i] = new int*[5];
        for (int j = 0; j < 5; j++) {
            HashTable* table;
            results[i][j] = new int[3]();
            if (i == 0) {
                table = new OpenHashTable(m);
            } else if (i == 1) {
                table = new QHashTable(m, k);
            } else {
                table = new DHashTable(m, k, p);
            }

            results[i][j][0] = testInsert(table, 5, maxInsertions[j], maxRange);
            auto tmp = testFind(table, maxRange);
            results[i][j][1] = tmp[0];
            results[i][j][2] = tmp[1];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            std::cout << "Open Hashing Performance\n";
        } else if (i == 1) {
            std::cout << "Quadratic Hashing Performance\n";
        } else {
            std::cout << "Double Hashing Performance\n";
        }

        for (int j = 0; j < 3; j++)
            printRow(results[i], j);
        std::cout << std::endl;
    }

    return 0;
}