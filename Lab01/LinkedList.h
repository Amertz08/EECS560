#ifndef EECS560_LINKEDLIST_H
#define EECS560_LINKEDLIST_H

#include "Node.h"

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
    void _erase(Node* tmp, int value);
    void print();
    Node* find(int value);
};


#endif //EECS560_LINKEDLIST_H
