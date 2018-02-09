#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "QHashTable.hpp"
#include "DHashTable.hpp"
using namespace std;

/**
 * Prints menu UI and takes input
 * @return : Input selection value
 */
int usage(int m, int k, int p) {
    int input;
    cout << "m=" << m << " k=" << k << " p=" << p << endl
         << "1 - Insert\n"
         << "2 - Delete\n"
         << "3 - Find\n"
         << "4 - Print\n"
         << "5 - Exit\n"
         << "Select a choice: ";
    cin >> input;
    return input;
}

/**
 * Prints CLI usage
 */
void cli_usage(string bin) {
    cout << "Usage: " << bin << " FILE_NAME M_VALUE K_VALUE P_VALUE\n";
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cli_usage(argv[0]);
        cerr << "Improper input\n";
        exit(1);
    } else {
        string fileName = argv[1];
        int m = atoi(argv[2]);
        int k = atoi(argv[3]);
        int p = atoi(argv[4]);
        ifstream file;

        cout << "Reading file " << fileName << endl;

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
                        cout << "Insert a value: ";
                        cin >> value;
                        qt.insert(value);
                        dt.insert(value);
                        break;
                    case 2:
                        cout << "Deleted a value: ";
                        cin >> value;
                        qt.remove(value);
                        dt.remove(value);
                        break;
                    case 3:
                        cout << "Find a value: ";
                        cin >> value;
                        if (qt.find(value)) {
                            cout << "Value found in Q Table\n";
                        } else {
                            cout << "Value not found in Q Table\n";
                        }

                        if (dt.find(value)) {
                            cout << "Value found in D Table\n";
                        } else {
                            cout << "Value not found in D Table\n";
                        }
                        break;
                    case 4:
                        cout << "Print QHash\n";
                        qt.print();
                        cout << "Print DHash\n";
                        dt.print();
                        break;
                    case 5:
                        cout << "Exiting...\n";
                        break;
                    default:
                        cout << "Invalid input";
                        break;
                }
            } while (choice != 5);
        } else {
            cerr << fileName << " did not open properly\n";
            exit(1);
        }
    }
    return 0;
}