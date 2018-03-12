#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>
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
float testInsert(HashTable* table, int testCount, int maxInsertions, int maxRange) {
    int totalTime = 0;
    for (int i = 0; i < testCount; i++) {
        std::srand((unsigned)i);
        totalTime += _testInsert(table, maxInsertions, maxRange);
    }
    return ((float)totalTime / (float)testCount) / (float)CLOCKS_PER_SEC;
}

float* testFind(HashTable* table, int maxRange) {
    auto totalTime = new float[2]();
    int tests = 10000;
    std::srand((unsigned)std::time(nullptr)); // Random seed
    for (int i = 0; i < tests; i++) {
        auto searchVal = generateNumber(maxRange);
        auto start = std::clock();
        auto found = table->Find(searchVal);
        auto elapsed = (float)(std::clock() - start) / (float)CLOCKS_PER_SEC;
        if (found) {
            totalTime[0] += elapsed;
        } else {
            totalTime[1] += elapsed;
        }
    }
    return totalTime;
}

void printRow(float **row, int n, int numTests) {
    std::string rowType;

    if (n == 0) {
        rowType = "Build ";
    } else if (n == 1) {
        rowType = "Found ";
    } else {
        rowType = "Not Found ";
    }

    std::cout << rowType;
    for (int j = 0; j < numTests; j++) {
        std::cout << fixed << std::setprecision(4) << row[j][n] << " ";
    }
    std::cout << std::endl;
}

void run() {
    const int m = 1000003;
    const int p = 997;
    const int k = 20;
    const int numTests = 5;
    int maxInsertions[5] = {100000, 200000, 300000, 400000, 500000};
    const int maxRange = 5000000;

    // Results array for each type of table
    float*** results = new float**[3];
    for (int i = 0; i < 3; i++) {
        // For each table type create a results array
        results[i] = new float*[numTests];
        for (int j = 0; j < numTests; j++) {
            HashTable* table;
            results[i][j] = new float[3]();
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
            // TODO: segfault if delete called
//            std::cout << "i: " << i << " j: " << j << "\n";
//            delete table;
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
            printRow(results[i], j, numTests);
        std::cout << std::endl;
    }
}

int main() {

    int k = 4;
    int p = 5;
    std::vector<int> data;
    std::fstream file("data.txt");

    if (file.is_open()) {
        int input;
        while (file >> input) {
            data.push_back(input);
        }
        file.close();
    } else {
        std::cerr << "data.txt could not be opened\n";
        exit(1);
    }

    int choice = 0;
    do {
        std::cout << "1 - Test HashTables\n"
                  << "2 - Performance Comparison\n"
                  << "3 - Exit\n"
                  << "> ";
        std::cin >> choice;

        int m;
        OpenHashTable* openTable;
        QHashTable* qTable;
        DHashTable* dTable;
        switch (choice) {
            case 1:
                std::cout << "Table size: ";
                std::cin >> m;
                openTable = new OpenHashTable(m);
                qTable = new QHashTable(m, k);
                dTable = new DHashTable(m, k, p);
                for (auto num : data) {
                    openTable->Insert(num);
                    qTable->Insert(num);
                    dTable->Insert(num);
                }

                std::cout << "Open Table\n";
                openTable->Print();
                std::cout << "QTable\n";
                qTable->Print();
                std::cout << "DTable\n";
                dTable->Print();

//                delete openTable;
                delete qTable;
                delete dTable;
                break;
            case 2:
                run();
                break;
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}