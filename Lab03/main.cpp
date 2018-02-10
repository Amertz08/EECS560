#include <iostream>
#include <fstream>
#include <string>
#include "QHashTable.hpp"
#include "DHashTable.hpp"

/**
 * Prints menu UI and takes input
 * @return : Input selection value
 */
int usage(int m, int k, int p) {
    int input;
    std::cout << "m=" << m << " k=" << k << " p=" << p << std::endl
         << "1 - Insert\n"
         << "2 - Delete\n"
         << "3 - Find\n"
         << "4 - Print\n"
         << "5 - Exit\n"
         << "Select a choice: ";
    std::cin >> input;
    return input;
}

/**
 * Prints CLI usage
 */
void cli_usage(const std::string &bin) {
    std::cout << "Usage: " << bin << " FILE_NAME M_VALUE K_VALUE P_VALUE\n";
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cli_usage(argv[0]);
        cerr << "Improper input\n";
        exit(1);
    } else {
        std::string fileName = argv[1];
        int m = std::atoi(argv[2]);
        int k = std::atoi(argv[3]);
        int p = std::atoi(argv[4]);
        std::ifstream file;

        std::cout << "Reading file " << fileName << std::endl;

        file.open(fileName);
        if (file) {
            int choice;
            int input;

            QHashTable qt = QHashTable(m, k);
            DHashTable dt = DHashTable(m, k, p);


            while (file >> input) {
                qt.insert(input);
                dt.insert(input);
            }


            do {
                choice = usage(m, k, p);
                int value;

                switch (choice) {
                    case 1:
                        std::cout << "Insert a value: ";
                        std::cin >> value;
                        qt.insert(value);
                        dt.insert(value);
                        break;
                    case 2:
                        std::cout << "Deleted a value: ";
                        std::cin >> value;
                        qt.remove(value);
                        dt.remove(value);
                        break;
                    case 3:
                        std::cout << "Find a value: ";
                        std::cin >> value;
                        if (qt.find(value)) {
                            std::cout << "Value found in Q Table\n";
                        } else {
                            std::cout << "Value not found in Q Table\n";
                        }

                        if (dt.find(value)) {
                            std::cout << "Value found in D Table\n";
                        } else {
                            std::cout << "Value not found in D Table\n";
                        }
                        break;
                    case 4:
                        std::cout << "Print QHash\n";
                        qt.print();
                        std::cout << "Print DHash\n";
                        dt.print();
                        break;
                    case 5:
                        std::cout << "Exiting...\n";
                        break;
                    default:
                        std::cout << "Invalid input";
                        break;
                }
            } while (choice != 5);
        } else {
            std::cerr << fileName << " did not open properly\n";
            exit(1);
        }
    }
    return 0;
}