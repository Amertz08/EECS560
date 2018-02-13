#include <iostream>
#include "BinarySearchTree.hpp"


BinarySearchTree::BinarySearchTree() { this->root = nullptr; }

BinarySearchTree::~BinarySearchTree() { delete this->root; }

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
    } else {
        if (target->getRight() == nullptr) {
            target->setRight(newNode);
            return;
        }
        this->_insert(target->getRight(), newNode);
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
        right->setParent(nullptr);
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
        left->setParent(nullptr);
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
        if (*target < *parent) {
            parent->setLeft(nullptr);
            if (left)
                this->_insert(parent, left);
            if (right)
                this->_insert(parent, right);
        } else {
            parent->setRight(nullptr);
            if (left)
                this->_insert(parent, left);
            if (right)
                this->_insert(parent, right);
        }
        delete target;
    } else {
        std::cout << "Value not found\n";
    }
}
