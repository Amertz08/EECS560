#ifndef EECS560_LINKEDLIST_H
#define EECS560_LINKEDLIST_H

#include "Node.hpp"

class LinkedList {
private:
    int length;
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    void insert(int value);
    void _insert(Node* tmp, int value);
    bool isEmpty();
    void erase(int value);
    void _erase(Node* current, int value);
    void print();
    Node* find(int value);
    int size();
};


#endif //EECS560_LINKEDLIST_H
