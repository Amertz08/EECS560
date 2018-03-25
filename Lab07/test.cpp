#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

#include "MinHeap.hpp"
#include "MaxHeap.hpp"

void printMinMax(KHeap* heap) {
    std::cout << "Min: " << heap->FindMin() << " Max: " << heap->FindMax() << std::endl;
}

void checkMinMax(KHeap* heap, int min, int max) {
    auto hmin = heap->FindMin();
    auto hmax = heap->FindMax();
    std::cout << "Expecting min: " << min << " Heap min: " << hmin << std::endl;
    assert(heap->FindMin() == min);
    std::cout << "Expecting max: " << max << " Heap max: " << hmax << std::endl;
    assert(heap->FindMax() == max);
}

void test(KHeap* heap) {
    heap->Print();
    heap->LevelOrder();
    printMinMax(heap);
    std::cout << "TEST: Calling BuildHeap\n";
    heap->BuildHeap();
    heap->Print();
    heap->LevelOrder();
    printMinMax(heap);
    checkMinMax(heap, 1, 402);

    std::cout << "TEST: Calling DeleteMin\n";
    heap->DeleteMin();
    heap->Print();
    heap->LevelOrder();
    printMinMax(heap);
    checkMinMax(heap, 11, 402);

    std::cout << "TEST: Calling DeleteMax\n";
    heap->DeleteMax();
    heap->Print();
    heap->LevelOrder();
    printMinMax(heap);
    checkMinMax(heap, 11, 317);

    std::cout << "TEST: Inserting 5\n";
    heap->Insert(5);
    heap->Print();
    heap->LevelOrder();
    printMinMax(heap);
    checkMinMax(heap, 5, 317);

    std::cout << "TEST: Inserting 500\n";
    heap->Insert(500);
    heap->Print();
    heap->LevelOrder();
    printMinMax(heap);
    checkMinMax(heap, 5, 500);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Incorrect usage\n";
        exit(0);
    }

    std::ifstream file;
    std::string fileName = argv[1];

    MaxHeap max(5);
    MinHeap min(5);

    file.open(fileName);
    if (file) {
        std::cout << "Reading file data.txt\n";
        int input;

        while (file >> input) {
            min.Push(input);
            max.Push(input);
        }
        file.close();

        std::cout << "Testing min\n";
        test(&min);
        std::cout << "Testing max\n";
        test(&max);
    } else {
        std::cerr << "Could not open file\n";
        exit(1);
    }
}
