#include <iostream>
#include "LinkedList.hpp"
#include "Node.hpp"
using namespace std;

LinkedList::LinkedList(){
    this->head = nullptr;
}

LinkedList::~LinkedList() {
    while (!this->isEmpty()) {
        Node* tmp = this->head;
        this->head = this->head->next;
        delete tmp;
    }
}

/**
 * Insert value at end of list
 * @param value : value to insert
 */
void LinkedList::insert(int value) {
    if (this->isEmpty()) {
        this->head = new Node(value);
        return;
    } else if (this->find(value) != nullptr) {
        cout << "Value is already in the list" << endl;
        return;
    }
    Node* tmp = this->head;
    return this->_insert(tmp, value);
}

/**
 * Insert front of list
 * @param value : value to insert
 */
void LinkedList::insert_front(int value) {
    if (this->find(value) != nullptr) {
        cout << "Value is already in the list" << endl;
        return;
    }
    Node* tmp = this->head;
    this->head = new Node(value);
    this->head->next = tmp;
    return;
}

/**
 * Recursive helper function for insert
 * @param tmp : ptr to target node
 * @param value : value to insert
 */
void LinkedList::_insert(Node *tmp, int value) {
    if (tmp->next == nullptr) {
        tmp->next = new Node(value);
        return;
    } else {
        return this->_insert(tmp->next, value);
    }
}

/**
 * Checks if list is empty or not
 * @return bool
 */
bool LinkedList::isEmpty() {
    return this->head == nullptr;
}

/**
 * Erase given value from list
 * @param value : value to delete
 */
void LinkedList::erase(int value) {
    Node* tmp;
    if (this->isEmpty()) {
        // Empty list do nothing
        return;
    } else {
        if (this->head->value == value) {
            // Value is at head
            tmp = this->head->next;
            delete this->head;
            this->head = tmp;
            return;
        }
    }
    // Value not at head
    tmp = this->head;
    return this->_erase(tmp, value);
}

/**
 * Erase recursive helper function
 * @param current : ptr to current node
 * @param value : value to delete
 */
void LinkedList::_erase(Node *current, int value) {
    Node* target = current->next;
    if (target == nullptr) {
        // Base case do nothing
        cout << value << " was not found in list" << endl;
        return;
    } else {
        if (target->value == value) {
            // Grab node after target
            current->next = target->next;
            delete target;
            cout << value << " has been deleted" << endl;
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
    if (this->isEmpty()) {
        cout << "Empty list" << endl;
    } else {
        Node* tmp = this->head;
        while(tmp != nullptr) {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

/**
 * Returns pointer to Node if found else nullptr
 * @param value : value to look for
 * @return ptr to node or nullptr
 */
Node* LinkedList::find(int value) {
    if (this->isEmpty()) {
        return nullptr;
    } else {
        Node* tmp = this->head;
        while(tmp != nullptr) {
            if (tmp->value == value) {
                return tmp;
            }
            tmp = tmp->next;
        }
        // EOL should be nullptr here
        return tmp;
    }
}
