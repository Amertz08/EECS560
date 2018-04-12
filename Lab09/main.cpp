#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <ctime>

#include "MaxHeap.hpp"
#include "MinHeap.hpp"
#include "BinarySearchTree.hpp"

#define NUM_TESTS 5
#define PRECISION 4
#define CASE_COUNT 5

const int CASES[CASE_COUNT] = { 1000000, 2000000, 3000000, 4000000, 5000000 };

/**
 * Generates a random value between 1 and 5,000,000
 * @return random integer value
 */
int RandomValue()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);

    std::uniform_int_distribution<int> distribution(1, 5000000);
    return distribution(generator);
}

/**
 * Runs Build/DeleteMin/DeleteMax cases
 * @param tree
 * @param valueCount : number of random values
 * @return double[3] with results from 3 tests
 */
double* TestBSTCase(BinarySearchTree* tree, int valueCount)
{
    auto results = new double[3]();

    double sum = 0.00;
    for (int i = 0; i < valueCount; i++) {
        auto val = RandomValue();
        auto s = clock();
        tree->insert(val);
        auto e = clock();
        sum += (e - s);
    }
    results[0] = sum / (double)CLOCKS_PER_SEC;

    sum = 0.00;
    for (int i = 0; i < 1000; i++) {
        auto s = clock();
        tree->deleteMin();
        auto e = clock();
        sum += (e - s);
    }
    results[1] = sum / (double)CLOCKS_PER_SEC;

    sum = 0.00;
    for (int i = 0; i < 1000; i++) {
        auto s = clock();
        tree->deleteMax();
        auto e = clock();
        sum += (e - s);
    }
    results[2] = sum / (double)CLOCKS_PER_SEC;
    return results;
}

/**
 * Finds average value for Build/DeleteMin/DeleteMax for NUM_TESTS
 * @param count : Test case count
 * @return double[3] with average results for 3 tests features
 */
double* FindAvgBST(int count)
{
    BinarySearchTree* tree;
    auto avgs = new double[3]();
    for (int i = 0; i < NUM_TESTS; i++) {
        tree = new BinarySearchTree();
        auto r = TestBSTCase(tree, count);
        for (int j = 0; j < 3; j++)
            avgs[j] += (r[j] / NUM_TESTS);
        delete tree;
    }
    return avgs;
}

/**
 * Runs BST tests
 * @return 3 x CASE_COUNT avg execution time array for Build/DeleteMin/DeleteMax
 */
double** TestBST()
{
    auto results = new double*[CASE_COUNT];

    for (int i = 0; i < CASE_COUNT; i++) {
            results[i] = FindAvgBST(CASES[i]);
    }
    return results;
}

double* TestHeapCase(KHeap* heap, int valueCount)
{
    auto results = new double[3]();


    for (int i = 0; i < valueCount; i++) {
        auto val = RandomValue();
        heap->Push(val);
    }

    auto start = clock();
    heap->BuildHeap();
    auto end = clock();
    results[0] = (end - start) / (double)CLOCKS_PER_SEC;

    double diff = 0.00;
    for (int i = 0; i < 1000; i++) {
        auto s = clock();
        heap->DeleteMin();
        auto e = clock();
        diff += (e - s) / (double)CLOCKS_PER_SEC;
    }
    results[1] = diff;

    diff = 0.00;
    for (int i = 0; i < 1000; i++) {
        auto s = clock();
        heap->DeleteMax();
        auto e = clock();
        diff += (e - s) / (double)CLOCKS_PER_SEC;
    }
    results[2] = diff;

    return results;
}

double* FindAvgHeap(const bool isMax, int count)
{
    auto avgs = new double[3]();
    KHeap* heap;
    for (int i = 0; i < NUM_TESTS; i++) {
        // Create new heap for each test
        if (isMax)
            heap = new MaxHeap(5);
        else
            heap = new MinHeap(5);

        auto r = TestHeapCase(heap, count);
        for (int j = 0; j < 3; j++)
            avgs[j] += (r[j] / NUM_TESTS);
        delete heap;
    }
    return avgs;
}

double** TestHeap(const bool isMax)
{
    auto results = new double*[CASE_COUNT];

    for (int i = 0; i < CASE_COUNT; i++) {
        results[i] = FindAvgHeap(isMax, CASES[i]);
    }
    return results;
}

void PrintResults(double** r, const std::string type)
{
    std::cout << "          " << type << " result\n" << "          ";

    for (auto c : CASES) {
        std::cout << c << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < 3; i++) {
        if (i == 0)
            std::cout << "Build     ";
        else if (i ==1)
            std::cout << "DeleteMin ";
        else
            std::cout << "DeleteMax ";
        for (int j = 0; j < CASE_COUNT; j++) {
            std::cout.precision(PRECISION);
            std::cout << std::fixed << r[j][i] << "  ";
        }
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {

    auto maxResults = TestHeap(true);
    PrintResults(maxResults, "Max");

    auto minResults = TestHeap(false);
    PrintResults(minResults, "Min");

    auto bstResults = TestBST();
    PrintResults(bstResults, "BST");

}
