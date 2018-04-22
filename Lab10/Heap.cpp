#include <iostream>

#include "Heap.hpp"

Heap::~Heap() { this->_delete(this->_root); }

bool Heap::_empty() { return this->_root == nullptr; }

void Heap::_swap(Node *target) {
    // Get right child
    auto tmp = target->getRight();

    // Set right child as left node
    target->setRight(target->getLeft());

    // Set left child as right node
    target->setLeft(tmp);
}

void Heap::_delete(Node *target) {
    if (!target)
        return;

    this->_delete(target->getLeft());
    this->_delete(target->getRight());
    delete target;
}

void Heap::_preOrder(Node *target) {
    if (!target)
        return;

    std::cout << target->getValue() << " ";
    this->_preOrder(target->getLeft());
    this->_preOrder(target->getRight());
}

void Heap::PreOrder() {
    if (this->_empty()) {
        std::cout << "Empty tree\n";
        return;
    }
    this->_preOrder(this->_root);
    std::cout << std::endl;
}
