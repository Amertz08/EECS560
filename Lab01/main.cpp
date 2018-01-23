#include <iostream>
#include <fstream>
#include "LinkedList.hpp"
using namespace std;

int usage() {
    int input;
    cout << "1 - Insert" << endl;
    cout << "2 - Delete" << endl;
    cout << "3 - Find" << endl;
    cout << "4 - Print" << endl;
    cout << "5 - Length" << endl;
    cout << "6 - Exit" << endl;
    cout << "Select a choice: ";
    cin >> input;
    return input;
}

int main(int argc, char** argv) {

    LinkedList list = LinkedList();

    if (argc == 1) {
        cout << "Please provide an input file" << endl;
        return 0;
    } else if (argc > 1) {
        string file_name = argv[1];
        ifstream file;

        cout << "Attempting to read " << file_name << endl;

        file.open(file_name);
        if (!file) {
            cerr << "Could not find file " << file_name << endl;
            exit(1);
        }

        int n;
        while (file >> n) {
            list.insert(n);
        }
        list.print();

        while (true) {
            int pick = usage();
            switch (pick) {
                int val;
                case 1:
                    cout << "Insert value: ";
                    cin >> val;
                    list.insert(val);
                    break;
                case 2:
                    cout << "Delete a value: ";
                    cin >> val;
                    list.erase(val);
                    break;
                case 3:
                    cout << "Find a value: ";
                    cin >> val;
                    Node* target;
                    target = list.find(val);
                    if (target == nullptr) {
                        cout << "Value could not be found" << endl;
                    } else {
                        cout << "Value found" << endl;
                    }
                    break;
                case 4:
                    list.print();
                    break;
                case 5:
                    cout << "Length: " << list.size() << endl;
                    break;
                case 6:
                    return 0;
                default:
                    break;
            }
        }
    }
    return 0;
}