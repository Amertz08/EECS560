#include <iostream>
#include "Leftist.hpp"

Leftist::Leftist() { this->_root = nullptr; }

Leftist::~Leftist() {
    this->_delete(this->_root);
}

bool Leftist::_shouldSwap(Node* target) {
#if DEBUG
    std::cout << "Checking swap\n";
#endif
    auto right = target->getRight();
    auto left = target->getLeft();
    if (!left) {
#if DEBUG
        std::cout << "left does not exist\n";
#endif
        return true;
    }

    if (!right) {
#if DEBUG
        std::cout << "right does not exist\n";
#endif
        return false;
    }
    return left->rank() < right->rank();
}
