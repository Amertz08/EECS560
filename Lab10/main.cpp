#include <iostream>

#include "Skew.hpp"
#include "Leftist.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " FILENAME\n";
        exit(1);
    }

    Leftist lh;
    Skew sk;

    lh.BuildHeap(argv[1]);
    sk.BuildHeap(argv[1]);
    std::cout << "Heaps built\n";

    int choice = 0;

    do {
        std::cout
                << "1 - Insert\n"
                << "2 - DeleteMin\n"
                << "3 - preorder\n"
                << "4 - inorder\n"
                << "5 - levelorder\n"
                << "6 - exit\n";
        std::cin >> choice;
        int val;

        switch (choice) {
            case 1:
                std::cout << "Insert value: ";
                std::cin >> val;
                lh.Insert(val);
                sk.Insert(val);
                break;
            case 2:
                lh.DeleteMin();
                sk.DeleteMin();
                break;
            case 3:
                std::cout << "Printing Leftist Heap\n";
                lh.PreOrder();
                std::cout << "Print Skew Heap\n";
                sk.PreOrder();
                break;
            case 4:
                std::cout << "Printing Leftist Heap\n";
                lh.InOrder();
                std::cout << "Print Skew Heap\n";
                sk.InOrder();
                break;
            case 5:
                std::cout << "Printing Leftist Heap\n";
                lh.LevelOrder();
                std::cout << "Print Skew Heap\n";
                sk.LevelOrder();
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid input\n";
        }
    } while (choice != 6);
}
