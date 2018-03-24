#include <iostream>
#include <fstream>
#include <string>

#include "MinHeap.hpp"
#include "MaxHeap.cpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Incorrect usage\n";
        exit(0);
    }

    std::ifstream file;
    std::string fileName = argv[1];
    std::cout << fileName << std::endl;

    MaxHeap min;

    file.open(fileName);
    if (file) {
        std::cout << "Reading file data.txt\n";
        int input;

        while (file >> input) {
            min.Push(input);
//            min.Insert(input);
        }
        file.close();

        min.Print();
        min.BuildHeap();
        min.Print();

        std::cout << "1 Min: " << min.FindMin() << " Max: " << min.FindMax() << std::endl;

        std::cout << "Deleting min\n";
        min.DeleteMin();
//        min.Print();
        std::cout << "2 Min: " << min.FindMin() << " Max: " << min.FindMax() << std::endl;

        std::cout << "Deleting max\n";
        min.DeleteMax();
//        min.Print();
        std::cout << "3 Min: " << min.FindMin() << " Max: " << min.FindMax() << std::endl;

        min.LevelOrder();
    } else {
        std::cerr << "Could not open file\n";
        exit(1);
    }
}