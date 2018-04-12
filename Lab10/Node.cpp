#include "Node.hpp"


Node::Node(int value) {
    this->value = value;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node() = default;

bool operator<(const Node &n1, const Node &n2) { return n1.value < n2.value; }

bool operator==(const Node &n1, const Node &n2) { return n1.value == n2.value; }

bool operator!=(const Node &n1, const Node &n2) { return n1.value != n2.value; }

bool operator>(const Node &n1, const Node &n2) { return n1.value > n2.value; }

bool operator>=(const Node &n1, const Node &n2) { return n1.value >= n2.value; }

bool operator<=(const Node &n1, const Node &n2) { return n1.value <= n2.value; }

Node* Node::getParent() { return this->parent; }

int Node::getValue() { return this->value; }

Node* Node::getLeft() { return this->left; }

Node* Node::getRight() { return this->right; }

void Node::setParent(Node *n) { this->parent = n; }

void Node::setLeft(Node *n) {
    this->left = n;
    if (n)
        n->parent = this;
}

void Node::setRight(Node *n) {
    this->right = n;
    if (n)
        n->parent = this;
}

void Node::setValue(int value) { this->value = value; }
