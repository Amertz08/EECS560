#include <iostream>
#include <fstream>

#include "MinMax.hpp"

int main(int argc, char* argv[]) {
    std::ifstream file;

    file.open("data.txt");
    if (!file) {
        std::cerr << "Could not open data.txt\n";
        exit(1);
    }

    MinMax min;

    int input;
    while (file >> input)
        min.Push(input);

    min.Print();
    std::cout << "Values inserted\n";
}