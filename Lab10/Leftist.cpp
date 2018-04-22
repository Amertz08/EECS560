#include <iostream>
#include "Leftist.hpp"

#define DEBUG 1

void NOT_IMPLEMENTED(const std::string &name)
{
    std::cout << name << " not implemented";
}

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

void Leftist::_concat(Node *leftHeap, Node *rightHeap) {
#if DEBUG
    std::cout << "left: " << leftHeap->getValue() << " right: " << rightHeap->getValue() << std::endl;
#endif
    auto rightChild = leftHeap->getRight();
    if (rightChild) {
#if DEBUG
        std::cout << "Right child exists\n";
#endif
        if (*rightChild <= *rightHeap) {
#if DEBUG
            std::cout << "rightChild: "
                         << rightChild->getValue()
                      << " <= rightHeap: "
                         << rightHeap->getValue()
                      << std::endl;
#endif
            this->_concat(rightChild, rightHeap);
            if (this->_shouldSwap(rightChild)) {
#if DEBUG
                std::cout << "Swapping rightChild...\n";
#endif
                this->_swap(rightChild);
            }
        }
        else {
#if DEBUG
            std::cout << "rightChild: "
                      << rightChild->getValue()
                      << " > rightHeap: "
                      << rightHeap->getValue()
                      << std::endl;
#endif
            this->_concat(rightHeap, rightChild);
            if (this->_shouldSwap(rightHeap)) {
#if DEBUG
                std::cout << "Swapping rightHeap...\n";
#endif
                this->_swap(rightHeap);
            }
        }
    } else {
        // Right Child does not exist so attach and possibly swap
#if DEBUG
        std::cout << "Setting: "
                     << rightHeap->getValue()
                  << " as right child of: "
                     << leftHeap->getValue()
                  << std::endl;
#endif
        auto parent = rightHeap->getParent();
        if (parent) {
#if DEBUG
            std::cout << "Parent exists\n";
#endif
            parent->setRight(leftHeap);
        }
        leftHeap->setRight(rightHeap);
        if (this->_shouldSwap(leftHeap)) {
#if DEBUG
            std::cout << "Swapping leftHeap...\n";
#endif
            this->_swap(leftHeap);
        }
    }
}

void Leftist::Insert(int value) {
#if DEBUG
    std::cout << "Inserting: " << value << std::endl;
#endif
    auto newNode = new Node(value);
    if (this->_empty()) {
#if DEBUG
        std::cout << "Adding at root\n";
#endif
        this->_root = newNode;
    } else {
        if (*this->_root > *newNode) {
#if DEBUG
            std::cout << "Root: "
                     << this->_root->getValue()
                     << " > newNode: "
                    << newNode->getValue()
                      << "\n";
#endif
            // Swap root
            auto tmp = this->_root;
            this->_root = newNode;
            this->_concat(this->_root, tmp);
        } else {
#if DEBUG
            std::cout << "Root: "
                        << this->_root->getValue()
                        << " <= newNode: "
                        << newNode->getValue() << "\n";
#endif
            this->_concat(this->_root, newNode);
        }
    }
    if (this->_shouldSwap(this->_root)) {
#if DEBUG
        std::cout << "Swapping root...\n";
#endif
        this->_swap(this->_root);
    }
}

void Leftist::DeleteMin() { NOT_IMPLEMENTED("DeleteMin"); }

int Leftist::FindMin() { NOT_IMPLEMENTED("FindMin"); return 0; }

void Leftist::InOrder() { NOT_IMPLEMENTED("InOrder"); }

void Leftist::LevelOrder() { NOT_IMPLEMENTED("LevelOrder"); }
