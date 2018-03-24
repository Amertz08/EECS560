#include <iostream>
#include <fstream>
#include <string>
#include "MinHeap.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Incorrect usage\n";
        exit(0);
    }

    std::ifstream file;
    std::string fileName = argv[1];
    std::cout << fileName << std::endl;

    MinHeap min;

    file.open(fileName);
    if (file) {
        std::cout << "Reading file data.txt\n";
        int input;

        while (file >> input) {
//            min.Push(input);
            min.Insert(input);
        }
        file.close();

//        min.Print();
        min.BuildHeap();
        min.Print();
    } else {
        std::cerr << "Could not open file\n";
        exit(1);
    }
}