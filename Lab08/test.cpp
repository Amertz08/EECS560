#include <iostream>
#include <fstream>

#include "MinMaxHeap.hpp"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " filename\n";
        exit(1);
    }
    std::ifstream file;

    MinMaxHeap min;

    std::cout << "opening: " << argv[1] << std::endl;
    file.open(argv[1]);
    if (file) {
        int input;
        while (file >> input) {
            std::cout << "Inserting: " << input << std::endl;
            min.Push(input);
        }
        file.close();

        min.Print();

        std::cout << "TEST: Calling BuildHeap\n";
        min.BuildHeap();
        min.Print();
    } else {
        std::cerr << "Could not open file data.txt\n";
        exit(1);
    }
}