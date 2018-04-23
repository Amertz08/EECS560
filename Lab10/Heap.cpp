#include <iostream>
#include <fstream>

#include "Heap.hpp"

Heap::Heap() { this->_root = nullptr; }

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

void Heap::_concat(Node *leftHeap, Node *rightHeap) {
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

int Heap::FindMin() {
    if (this->_empty())
        return -1;
    return this->_root->getValue();
}

void Heap::DeleteMin() {
    if (this->_empty()) {
        std::cout << "Empty Tree\n";
        return;
    }

    auto left = this->_root->getLeft();
    auto right = this->_root->getRight();

    if (!left) { // no left i.e. no right either
        delete this->_root;
        return;
    }

    if (!right) { // no right i.e. only left
        delete this->_root;
        this->_root = left;
        return;
    }

    if (*left <= *right) {
        // left <= right then left should be new root
        this->_root = left;
        this->_concat(this->_root, right);
    } else {
        // left > right then right should be new root
        this->_root = right;
        this->_concat(this->_root, left);
    }

    if (this->_shouldSwap(this->_root)) {
#if DEBUG
        std::cout << "Swapping root...\n";
#endif
        this->_swap(this->_root);
    }
}

void Heap::Insert(int value) {
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

void Heap::_inOrder(Node *target, std::list<int>* l) {
    if (!target)
        return;
    l->push_back(target->getValue());
    this->_inOrder(target->getLeft(), l);
    this->_inOrder(target->getRight(), l);
}

void Heap::InOrder() {
    std::list<int> values;
    this->_inOrder(this->_root, &values);
    values.sort();
    for (auto val : values)
        std::cout << val << " ";
    std::cout << std::endl;
}

void Heap::_printLvl(Node *n, int lvl) {
    if (!n)
        return;

    if (lvl == 1)
        std::cout << n->getValue() << " ";
    else {
        this->_printLvl(n->getLeft(), lvl - 1);
        this->_printLvl(n->getRight(), lvl - 1);
    }
}

int Heap::_height(Node* n) {
    if (!n)
        return 0;

    auto lheight = this->_height(n->getLeft());
    auto rheight = this->_height(n->getRight());
#if DEBUG
    std::cout << "lheight: " << lheight << " rheight: " << rheight << std::endl;
#endif

    return lheight > rheight ? lheight + 1 : rheight + 1;
}

int Heap::Height() { return this->_height(this->_root); }

void Heap::LevelOrder() {
    auto height = this->Height();
#if DEBUG
    std::cout << "height: " << height << std::endl;
#endif

    for (int i = 1; i < height; i++) {
        this->_printLvl(this->_root, i);
        std::cout << std::endl;
    }
}

void Heap::BuildHeap(const std::string fileName) {
    std::ifstream file;

    file.open(fileName);
    if (!file) {
        std::cerr << "Could not open file: " << fileName << std::endl;
        exit(1);
    }

    int input;
    while (file >> input)
        this->Insert(input);
    file.close();
}