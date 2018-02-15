#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.hpp"

int usage() {
    int input;
    std::cout << "1 - Insert\n"
              << "2 - DeleteMin\n"
              << "3 - DeleteMax\n"
              << "4 - Delete\n"
              << "5 - FindMin\n"
              << "6 - FindMax\n"
              << "7 - Preorder\n"
              << "8 - Inorder\n"
              << "9 - Postorder\n"
              << "10 - Exit\n"
              << "Select a choice: ";
    std::cin >> input;
    return input;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " INPUT_FILE\n";
        exit(1);
    }

    BinarySearchTree tree;
    std::string fileName = argv[1];
    std::ifstream file;

    std::cout << "Reading file " << fileName << std::endl;
    file.open(fileName);
    if (file) {
        int input;

        while (file >> input) {
            std::cout << "Inserting: " << input << std::endl;
            tree.insert(input);
        }
        file.close();

        int choice = 0;

        while (choice != 10) {
            choice = usage();
            int value;
            Node* target;

            switch (choice) {
                case 1:
                    std::cout << "Insert a value: ";
                    std::cin >> value;
                    tree.insert(value);
                    break;
                case 2:
                    tree.deleteMin();
                    break;
                case 3:
                    tree.deleteMax();
                    break;
                case 4:
                    std::cout << "Delete a value: ";
                    std::cin >> value;
                    tree.deleteValue(value);
                    break;
                case 5:
                    target = tree.findMin();
                    if (target) {
                        std::cout << "Min value: " << target->getValue() << std::endl;
                    } else {
                        std::cout << "Empty tree\n";
                    }
                    break;
                case 6:
                    target = tree.findMax();
                    if (target) {
                        std::cout << "Max value: " << target->getValue() << std::endl;
                    } else {
                        std::cout << "Empty tree\n";
                    }
                    break;
                case 7:
                    tree.preOrder();
                    break;
                case 8:
                    tree.inOrder();
                    break;
                case 9:
                    tree.postOrder();
                    break;
                case 10:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid input\n";
            }
        }
    } else {
        std::cout << fileName << " could not be opened\n";
    }

    return 0;
}