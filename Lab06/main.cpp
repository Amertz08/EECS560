#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <mutex>
#include <iomanip>
#include <fstream>
#include <vector>
#include "OpenHashTable.hpp"
#include "DHashTable.hpp"
#include "QHashTable.hpp"

const int AVG_TEST_COUNT = 5;
int insertTimes[AVG_TEST_COUNT] = {0};
std::mutex findMutex;

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
void _testInsert(HashTable* table, int threadID, int maxInsertions, int maxRange) {
    if (!table) {
        std::cerr << "Received nullptr\n";
        exit(1);
    }
    std::srand((unsigned)threadID);
    int insertTime = 0;
    for (int i = 0; i < maxInsertions; i++) {
        auto start = std::clock();
        table->Insert(generateNumber(maxRange));
        insertTime += std::clock() - start;
    }
    insertTimes[threadID] = insertTime;
}

/**
 * Finds average insert time over the number of test cases for the given amount of insertions
 * @param table : table to insert into
 * @param testCount : amount of times to test insert
 * @param maxInsertions : total number of insertions
 * @param maxRange : highest value of random number range
 * @return : average time for the amount of test cases
 */
float testInsert(HashTable* tables[], int maxInsertions, int maxRange) {
    int totalTime = 0;
    std::thread t[AVG_TEST_COUNT];
    for (int i = 0; i < AVG_TEST_COUNT; i++) {
        t[i] = std::thread(_testInsert, tables[i], i, maxInsertions, maxRange);
    }

    for (int i = 0; i < AVG_TEST_COUNT; i++) {
        t[i].join();
        totalTime += insertTimes[i];
    }
    return ((float)totalTime / (float)AVG_TEST_COUNT) / (float)CLOCKS_PER_SEC;
}

float findTime[2] = {0};

void _testFind(HashTable* table, int maxRange) {
    if (!table) {
        std::cerr << "No table\n";
        exit(1);
    }
    int tests = 10000;
    std::srand((unsigned)std::time(nullptr));
    for (int i = 0; i < tests; i++) {
        auto searchVal = generateNumber(maxRange);
        auto start = std::clock();
        auto found = table->Find(searchVal);
        auto elapsed = (float)(std::clock() - start) / (float)CLOCKS_PER_SEC;
        findMutex.lock();
        if (found) {
            findTime[0] += elapsed;
        } else {
            findTime[1] += elapsed;
        }
        findMutex.unlock();
    }
}

/**
 * Tests the performance of find for the given table
 * @param table : table to test
 * @param maxRange : max value for range of random numbers
 * @return : Average time of tests
 */
float* testFind(HashTable* tables[], int maxRange) {
    std::thread t[AVG_TEST_COUNT];
    for (int i = 0; i < AVG_TEST_COUNT; i++) {
        t[i] = std::thread(_testFind, tables[i], maxRange);
    }

    for (int i = 0; i < AVG_TEST_COUNT; i++) {
        t[i].join();
    }

    findTime[0] = findTime[0] / AVG_TEST_COUNT;
    findTime[1] = findTime[1] / AVG_TEST_COUNT;
    return findTime;
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
            HashTable* tables[AVG_TEST_COUNT];
            results[i][j] = new float[3]();
            for (int x = 0; x < AVG_TEST_COUNT; x++) {
                if (i == 0) {
                    tables[x] = new OpenHashTable(m);
                } else if (i == 1) {
                    tables[x] = new QHashTable(m, k);
                } else {
                    tables[x] = new DHashTable(m, k, p);
                }
            }
            results[i][j][0] = testInsert(tables, maxInsertions[j], maxRange);

            for (int x = 0; x < AVG_TEST_COUNT; x++) {
                insertTimes[x] = 0;
            }

            for (int x = 0; x < AVG_TEST_COUNT; x++) {
                auto tmp = testFind(tables, maxRange);
                results[i][j][1] = tmp[0];
                results[i][j][2] = tmp[1];
                delete tmp;
            }
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

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < numTests; j++) {
            delete[] results[i][j];
        }
        delete[] results[i];
    }
}

/*
 * TODO: Memleaks
 * TODO: OpenHash destructor
 * TODO: multithreading
 */
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