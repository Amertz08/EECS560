#include <iostream>
#include "Leftist.hpp"

void NOT_IMPLEMENTED(const std::string &name)
{
    std::cout << name << " not implemented";
}

Leftist::Leftist() { this->_root = nullptr; }

Leftist::~Leftist() {
    NOT_IMPLEMENTED("Leftist destructor");
}

void Leftist::BuildHeap() {
    NOT_IMPLEMENTED("Leftist BuildHeap");
}

bool Leftist::_shouldSwap(Node* target) {

}

void Leftist::_insert(Node *leftHeap, Node *rightHeap) {
    auto rightChild = leftHeap->getRight();
    if (rightChild) {
        if (rightChild <= rightHeap)
            this->_insert(rightChild, rightHeap);
        else
            this->_insert(rightHeap, rightChild);
    } else {
        // Right Child does not exist so attach and possibly swap
        leftHeap->setRight(rightHeap);
        if (this->_shouldSwap(leftHeap))
            this->_swap(leftHeap);
    }
}

void Leftist::Insert(int value) {
    auto newNode = new Node(value);
    if (this->_empty()) {
        this->_root = newNode;
    } else {
        if (this->_root <= newNode) {
            this->_insert(this->_root, newNode);
        } else {
            this->_insert(newNode, this->_root);
        }
    }
}