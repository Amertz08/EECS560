#include <iostream>
#include "BinarySearchTree.hpp"


BinarySearchTree::BinarySearchTree() { this->root = nullptr; }

BinarySearchTree::~BinarySearchTree() { this->_delete(this->root); }

void BinarySearchTree::_delete(Node *target) {
    if (target->getLeft())
        this->_delete(target->getLeft());
    if (target->getRight())
        this->_delete(target->getRight());
    delete target;
}

bool BinarySearchTree::empty() { return this->root == nullptr; }

void BinarySearchTree::insert(int value) {
    auto newNode = new Node(value);
    if (this->empty()) {
        this->root = newNode;
        return;
    }
    this->_insert(this->root, newNode);
}

void BinarySearchTree::_insert(Node *target, Node* newNode) {
    if (*newNode < *target) {
        if (target->getLeft() == nullptr) {
            target->setLeft(newNode);
            return;
        }
        this->_insert(target->getLeft(), newNode);
    } else if (*newNode > *target){
        if (target->getRight() == nullptr) {
            target->setRight(newNode);
            return;
        }
        this->_insert(target->getRight(), newNode);
    } else {
        Node* rightTree = target->getRight();
        if (rightTree) {
            newNode->setRight(rightTree);
            rightTree->setParent(newNode);
        }
        target->setRight(newNode);
        newNode->setParent(target);
    }
}

Node* BinarySearchTree::find(int value) {
    if (this->empty()) {
        return this->root;
    }
    return this->_find(this->root, value);
}

Node* BinarySearchTree::_find(Node *target, int value) {
    if (!target)
        return nullptr;

    if (target->getValue() == value) {
        return target;
    } else if (value < target->getValue()) {
        return this->_find(target->getLeft(), value);
    } else {
        return this->_find(target->getRight(), value);
    }
}

Node* BinarySearchTree::findMin() {
    if (this->empty())
        return nullptr;
    return this->_findMin(this->root);
}

Node* BinarySearchTree::_findMin(Node *target) {
    if (target->getLeft() == nullptr)
        return target;
    return this->_findMin(target->getLeft());
}

Node* BinarySearchTree::findMax() {
    if (this->empty())
        return nullptr;
    return this->_findMax(this->root);
}

Node* BinarySearchTree::_findMax(Node *target) {
    if (target->getRight() == nullptr)
        return target;
    return this->_findMax(target->getRight());
}

void BinarySearchTree::deleteMin() {
    if (this->empty()) {
        std::cout << "Cannot delete. BST empty.\n";
        return;
    }
    Node* target = this->findMin();
    Node* parent = target->getParent(); // Node ptr or nullptr
    Node* right = target->getRight(); // Node ptr or nullptr

    if (parent) {
        parent->setLeft(right);
    } else {
        if (right) {
            right->setParent(nullptr);
        }
        this->root = right;
    }
    delete target;
}

void BinarySearchTree::deleteMax() {
    if (this->empty()) {
        std::cout << "Cannot delete. BST empty.\n";
        return;
    }
    Node* target = this->findMax();
    Node* parent = target->getParent();
    Node* left = target->getLeft(); // Node ptr or nullptr

    if (parent) {
        parent->setRight(left);
    } else {
        if (left) {
            left->setParent(nullptr);
        }
        this->root = left;
    }
    delete target;
}

void BinarySearchTree::preOrder() {
    if (this->empty()) {
        std::cout << "Empty tree\n";
        return;
    }
    this->_preOrder(this->root);
}

void BinarySearchTree::_preOrder(Node *target) {
    std::cout << target->getValue() << std::endl;

    if (target->getLeft()) {
        this->_preOrder(target->getLeft());
    }
    if (target->getRight()) {
        this->_preOrder(target->getRight());
    }
}

void BinarySearchTree::inOrder() {
    if (this->empty()) {
        std::cout << "Empty tree\n";
        return;
    }
    this->_inOrder(this->root);
}

void BinarySearchTree::_inOrder(Node *target) {
    if (target->getLeft()) {
        this->_inOrder(target->getLeft());
    }

    std::cout << target->getValue() << std::endl;

    if (target->getRight()) {
        this->_inOrder(target->getRight());
    }
}

void BinarySearchTree::postOrder() {
    if (this->empty()) {
        std::cout << "Empty tree\n";
        return;
    }
    this->_postOrder(this->root);
}

void BinarySearchTree::_postOrder(Node *target) {
    if (target->getLeft()) {
        this->_postOrder(target->getLeft());
    }

    if (target->getRight()) {
        this->_postOrder(target->getRight());
    }

    std::cout << target->getValue() << std::endl;
}

void BinarySearchTree::deleteValue(int value) {
    Node* target = this->find(value);

    if (target) {
        Node* parent = target->getParent();
        Node* left = target->getLeft();
        Node* right = target->getRight();
        if (parent) {
            if (left && right) {
                auto minNode = this->_findMin(right);
                minNode->setLeft(left);
                minNode->setParent(parent);
                left->setParent(minNode);

                if (*minNode < *parent) {
                    parent->setLeft(minNode);
                } else {
                    parent->setRight(minNode);
                }
                if (*minNode != *target) {
                    minNode->setRight(right);
                    right->setParent(minNode);
                }
            } else if (left) {
                if (*left < *parent) {
                    parent->setLeft(left);
                } else {
                    parent->setRight(left);
                }
            } else {
                if (*right < *parent) {
                    parent->setLeft(right);
                } else {
                    parent->setRight(right);
                }
            }
        } else {
            // Value is at root
            if (left && right) {
                auto minNode = this->_findMin(right);
                minNode->setLeft(left);
                left->setParent(minNode);

                if (*minNode != *target) {
                    minNode->setRight(right);
                    right->setParent(minNode);
                }
                this->root = minNode;
            } else if (left) {
                this->root = left;
            } else {
                this->root = right;
            }
            this->root->setParent(nullptr);
        }
        delete target;
    } else {
        std::cout << "Value not found\n";
    }
}
