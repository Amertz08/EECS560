#include <iostream>
#include "LinkedList.hpp"
#include "Node.hpp"
using namespace std;

LinkedList::LinkedList(){
    this->length = 0;
    this->head = nullptr;
}

LinkedList::~LinkedList() {}

/**
 * Insert value at end of list
 * @param value : value to insert
 */
void LinkedList::insert(int value) {
    if (this->isEmpty()) {
        this->head = new Node(value);
        this->length++;
        return;
    }
    Node* tmp = this->head;
    return this->_insert(tmp, value);
}

/**
 * Recursive helper function for insert
 * @param tmp : ptr to target node
 * @param value : value to insert
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
 * @return bool
 */
bool LinkedList::isEmpty() {
    return this->length == 0;
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
 * Erase recursive helper function
 * @param current : ptr to current node
 * @param value : value to delete
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
    if (this->isEmpty()) {
        cout << "Empty list" << endl;
    } else {
        Node* tmp = this->head;
        cout << "List ";
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

/**
 * Gets length of list
 * @return size of list
 */
int LinkedList::size() {
    return this->length;
}