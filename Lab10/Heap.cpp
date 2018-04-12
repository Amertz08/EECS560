#include "Heap.hpp"

bool Heap::_empty() { return this->_root == nullptr; }

void Heap::_swap(Node *target) {
    // Get right child
    auto tmp = target->getRight();

    // Set right child as left node
    target->setRight(target->getLeft());

    // Set left child as right node
    target->setLeft(tmp);
}