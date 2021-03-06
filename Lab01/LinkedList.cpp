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

void LinkedList::_insert(Node *tmp, int value) {
    if (tmp->next == nullptr) {
        tmp->next = new Node(value);
        return;
    } else {
        return this->_insert(tmp->next, value);
    }
}

bool LinkedList::isEmpty() {
    return this->head == nullptr;
}

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
            return;
        } else {
            return this->_erase(target, value);
        }
    }
}

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
