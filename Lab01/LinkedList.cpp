#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList(){
    this->length = 0;
    this->head = nullptr;
}

LinkedList::~LinkedList() {}

/**
 * Insert value at end of list
 * @param value
 */
void LinkedList::insert(int value) {
    if (this->head == nullptr) {
        this->head = new Node(value);
        this->length++;
        return;
    }
    Node* tmp = this->head;
    return this->_insert(tmp, value);
}

/**
 * Recusive helper function for insert
 * @param tmp
 * @param value
 */
void LinkedList::_insert(Node *tmp, int value) {
    if (tmp->next == nullptr) {
        tmp->next = new Node(value);
        this->length++;
        return;
    } else {
        return this->_insert(tmp->next, value);
    }
}

/**
 * Checks if list is empty or not
 * @return
 */
bool LinkedList::isEmpty() {
    return this->length == 0;
}

/**
 * Erase given value from list
 * @param value
 */
void LinkedList::erase(int value) {
    Node* tmp;
    if (this->head == nullptr) {
        // Empty list do nothing
        return;
    } else {
        if (this->head->value == value) {
            // Value is at head
            tmp = this->head->next;
            delete this->head;
            this->length--;
            this->head = tmp;
            return;
        }
    }
    // Value not at head
    tmp = this->head;
    return this->_erase(tmp, value);
}

/**
 * Erase help function
 * @param current
 * @param value
 */
void LinkedList::_erase(Node *current, int value) {
    Node* target = current->next;
    if (target == nullptr) {
        // Base case do nothing
        return;
    } else {
        if (target->value == value) {
            // Grab node after target
            current->next = target->next;
            delete target;
            this->length--;
            return;
        } else {
            return this->_erase(target, value);
        }
    }
}

/**
 * Print list
 */
void LinkedList::print() {
    if (this->head == nullptr) {
        cout << "Empty list" << endl;
    } else {
        Node* tmp = this->head;
        cout << "List ";
        while(tmp != nullptr) {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
    }
}