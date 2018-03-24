#include <iostream>
#include <fstream>
#include <string>

#include "MinHeap.hpp"
#include "MaxHeap.hpp"

void printMinMax(KHeap* heap) {
    std::cout << "Min: " << heap->FindMin() << " Max: " << heap->FindMax() << std::endl;
}

void test(KHeap* heap) {
    heap->Print();
    heap->LevelOrder();
    printMinMax(heap);
    std::cout << "Calling BuildHeap\n";
    heap->BuildHeap();
    heap->Print();
    heap->LevelOrder();
    printMinMax(heap);

    std::cout << "Calling DeleteMin\n";
    heap->DeleteMin();
    heap->Print();
    heap->LevelOrder();
    printMinMax(heap);

    std::cout << "Calling DeleteMax\n";
    heap->DeleteMax();
    heap->Print();
    heap->LevelOrder();
    printMinMax(heap);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Incorrect usage\n";
        exit(0);
    }

    std::ifstream file;
    std::string fileName = argv[1];
    std::cout << fileName << std::endl;

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