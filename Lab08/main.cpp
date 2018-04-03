#include <iostream>
#include <fstream>

#include "MaxMinHeap.hpp"
#include "MinMaxHeap.hpp"


int main(int argc, char* argv[]) {
    std::ifstream file;

    file.open("data.txt");

    if (!file) {
        std::cerr << "Could not open data.txt\n";
        exit(1);
    }

    MinMaxHeap minHeap;
    MaxMinHeap maxHeap;
    int input;
    while (file >> input) {
        minHeap.Push(input);
        maxHeap.Push(input);
    }

    minHeap.BuildHeap();
    maxHeap.BuildHeap();

    int choice = 0;

    do {
        std::cout << "1 - Insert\n"
                  << "2 - DeleteMin\n"
                  << "3 - FindMin\n"
                  << "4 - FindMax\n"
                  << "5 - DeleteMax\n"
                  << "6 - LevelOrder\n"
                  << "7 - Exit\n"
                  << "> ";
        std::cin >> choice;

        int value;
        switch (choice) {
            case 1:
                std::cout << "Insert value: ";
                std::cin >> value;
                minHeap.Insert(value);
                maxHeap.Insert(value);
                break;
            case 2:
                minHeap.DeleteMin();
                maxHeap.DeleteMax();
                break;
            case 3:
                value = minHeap.FindMin();
                std::cout << "MinMaxHeap min: " << value << std::endl;
                value = maxHeap.FindMin();
                std::cout << "MaxMinHeap min: " << value << std::endl;
                break;
            case 4:
                value = minHeap.FindMax();
                std::cout << "MinMaxHeap max: " << value << std::endl;
                value = maxHeap.FindMax();
                std::cout << "MaxMinHeap max: " << value << std::endl;
                break;
            case 5:
                minHeap.DeleteMax();
                maxHeap.DeleteMax();
                break;
            case 6:
                std::cout << "Printing MinMaxHeap\n";
                minHeap.LevelOrder();
                std::cout << "Printing MaxMinHeap\n";
                maxHeap.LevelOrder();
                break;
            case 7:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 7);
}