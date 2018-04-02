#include <iostream>
#include <fstream>

#include "MinMaxHeap.hpp"

int main(int argc, char* argv[]) {
    std::ifstream file;

    file.open("data.txt");
    if (!file) {
        std::cerr << "Could not open data.txt\n";
        exit(1);
    }

    MinMaxHeap minHeap;

    int input;
    while (file >> input) {
        std::cout << input << " ";
        minHeap.Push(input);
    }
    std::cout << std::endl;
    minHeap.Print();
    minHeap.LevelOrder();


    std::cout << "Values inserted\n";

    auto min = minHeap.FindMin();
    auto max = minHeap.FindMax();
    std::cout << "Min: " << min << " Max: " << max << std::endl;

    std::cout << "Calling BuildHeap\n";
    minHeap.BuildHeap();
    minHeap.LevelOrder();

    min = minHeap.FindMin();
    max = minHeap.FindMax();
    std::cout << "Min: " << min << " Max: " << max << std::endl;

    minHeap.DeleteMin();
    minHeap.LevelOrder();
    min = minHeap.FindMin();
    max = minHeap.FindMax();
    std::cout << "Min: " << min << " Max: " << max << std::endl;

    minHeap.DeleteMax();
    minHeap.LevelOrder();
    min = minHeap.FindMin();
    max = minHeap.FindMax();
    std::cout << "Min: " << min << " Max: " << max << std::endl;
}