#include <iostream>
#include <fstream>
#include "TwoThreeTree.hpp"

void put(TwoThreeTree* t, int value) {
    std::cout << "TEST PUT: " << value << std::endl;
    t->Insert(value);
    if (!t->Find(value)) {
        std::cout << "Value: " << value << " not found\n";
        exit(1);
    }
    t->LevelOrder();
}

void find(TwoThreeTree* t, int value) {
    std::cout << "TEST FIND: " << value << std::endl;
    if (!t->Find(value)) {
        std::cout << "Value: " << value << " not found\n";
    }
}

int usage() {
    int input;
    std::cout << "1 - Insert\n"
              << "2 - DeleteMin\n"
              << "3 - DeleteMax\n"
              << "4 - FindMin\n"
              << "5 - FindMax\n"
              << "6 - Find\n"
              << "7 - Delete\n"
              << "8 - Level order\n"
              << "9 - Exit\n"
              << "Select a choice: ";
    std::cin >> input;
    return input;
}

int main() {
    TwoThreeTree tree;
//    tree.LevelOrder(); // Empty tree
//    if (!tree.Find(5)) {
//        "Tree should be empty\n";
//    }
//    put(&tree, 5); // 5
//    put(&tree, 1); // 2 5
//    put(&tree, 3); // 2 3 5
//    put(&tree, 6); // 2 3, 5 6
//    find(&tree, 5); // Should find at first node of second child of root
//    find(&tree, 2); // Should find at first node of first child of root
//    find(&tree, 3); // Should find at second node of first child of root
//    put(&tree, 4); // 2 3 4, 5 6
//    put(&tree, 10); // 2 3 4, 5 6 10
//    put(&tree, 12); // 2 3 4, 5 6, 10 12
//    put(&tree, 7); // 2 3 4, 5 6 7, 10 12
//    put(&tree, 9); // 2 3 4, 5 6 7, 9 10 12
//    put(&tree, 11); // 2 3 4, 5 6 7, 9 10, 11 12

    std::ifstream file;

    file.open("data.txt");

    if (file) {
        int input;
        while (file >> input) {
            tree.Insert(input);
        }
        file.close();

        int choice = 0;
        do {
            choice = usage();
            int value;
            Node* n = nullptr;

            switch (choice) {
                case 1:
                    std::cout << "Insert a value: ";
                    std::cin >> value;
                    tree.Insert(value);
                    break;
                case 2:
                    tree.DeleteMin();
                    break;
                case 3:
                    tree.DeleteMax();
                    break;
                case 4:
                    n = tree.FindMin();
                    if (n) {
                        std::cout << "Min value: " << n->GetKey() << std::endl;
                    }
                    break;
                case 5:
                    n = tree.FindMax();
                    if (n) {
                        std::cout << "Max value: " << n->GetKey() << std::endl;
                    }
                    break;
                case 6:
                    std::cout << "Find value: ";
                    std::cin >> value;
                    if (tree.Find(value)) {
                        std::cout << "Value found\n";
                    } else {
                        std::cout << "Value not found\n";
                    }
                    break;
                case 7:
                    std::cout << "Delete value: ";
                    std::cin >> value;
                    tree.Delete(value);
                    break;
                case 8:
                    tree.LevelOrder();
                    break;
                case 9:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice\n";
            }
        } while (choice != 9);
    } else {
        std::cout << "data.txt could not be opened\n";
        exit(1);
    }
}

