#include "LinkedList.h"
#include "Node.h"

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
    return this->length > 0;
}

void LinkedList::erase(int value) {
    Node* tmp = this->head;
    return this->_erase(tmp, value);
}

void LinkedList::_erase(Node *tmp, int value) {
    if (tmp == nullptr) {
        return;
    } else {
        if (tmp->value == value) {
            Node* next = tmp->next;
        }
    }
}