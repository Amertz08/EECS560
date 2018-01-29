#ifndef EECS560_LINKEDLIST_H
#define EECS560_LINKEDLIST_H

#include "Node.hpp"

class LinkedList {
private:
    Node* head;
    void _insert(Node* tmp, int value);
    void _erase(Node* current, int value);

public:
    LinkedList();
    ~LinkedList();
    void insert(int value);
    void insert_front(int value);
    bool isEmpty();
    void erase(int value);
    void print();
    Node* find(int value);
};


#endif //EECS560_LINKEDLIST_H
