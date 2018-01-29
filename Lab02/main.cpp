#include "HashTable.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * Prints menu UI and takes input
 * @return : Input selection value
 */
int usage() {
    int input;
    cout << "1 - Insert" << endl;
    cout << "2 - Delete" << endl;
    cout << "3 - Find" << endl;
    cout << "4 - Print" << endl;
    cout << "5 - Exit" << endl;
    cout << "Select a choice: ";
    cin >> input;
    return input;
}

int main(int argc, char* argv[]) {
    HashTable* table = nullptr;

    if (argc == 1) {
        cerr << "Please provide an input file" << endl;
        exit(1);
    } else {
        string file_name = argv[1];
        ifstream file;

        cout << "Reading file " << file_name << endl;

        file.open(file_name);
        if (file) {
            int n;
            file >> n;
            table = new HashTable(n);

            while (file >> n) {
                cout << "Inserting: " << n << endl;
                table->Insert(n);
            }
        } else {
            cerr << "Could not read file " << file_name << endl;
            exit(1);
        }

        while (true) {
            int input = usage();
            int val;
            switch (input) {
                case 1:
                    cout << "Insert a value: ";
                    cin >> val;
                    table->Insert(val);
                    break;
                case 2:
                    cout << "Delete a value: ";
                    cin >> val;
                    table->Delete(val);
                    break;
                case 3:
                    cout << "Find a value: ";
                    cin >> val;
                    if (table->Find(val)) {
                        cout << "Value in table" << endl;
                    } else {
                        cout << "Value NOT in table" << endl;
                    }
                    break;
                case 4:
                    table->Print();
                    break;
                case 5:
                    return 0;
                default:
                    cout << input << " is not a valid input" << endl;
                    break;
            }
        }
    }
}