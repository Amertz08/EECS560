#ifndef EECS560_LINKEDLIST_H
#define EECS560_LINKEDLIST_H

#include "Node.hpp"

class LinkedList {
private:
    Node* head;

    /**
     * Recursive helper function for insert
     * @param tmp : ptr to target node
     * @param value : value to insert
     */
    void _insert(Node* tmp, int value);

    /**
     * Erase recursive helper function
     * @param current : ptr to current node
     * @param value : value to delete
     */
    void _erase(Node* current, int value);

public:
    LinkedList();
    ~LinkedList();


    /**
     * Insert value at end of list
     * @param value : value to insert
     */
    void insert(int value);

    /**
     * Insert front of list
     * @param value : value to insert
     */
    void insert_front(int value);

    /**
     * Checks if list is empty or not
     * @return bool
     */
    bool isEmpty();

    /**
     * Erase given value from list
     * @param value : value to delete
     */
    void erase(int value);

    /**
     * Print list
     */
    void print();

    /**
     * Returns pointer to Node if found else nullptr
     * @param value : value to look for
     * @return ptr to node or nullptr
     */
    Node* find(int value);
};


#endif //EECS560_LINKEDLIST_H
