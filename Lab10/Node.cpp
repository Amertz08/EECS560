#include "Node.hpp"


Node::Node(int value) {
    this->setValue(value);
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

int Node::_rank(Node *target, int rank) {
    if (!target)
        return rank;

    rank++;
    auto leftRank = this->_rank(target->getLeft(), rank);
    auto rightRank = this->_rank(target->getRight(), rank);
    return leftRank < rightRank ? leftRank : rightRank;
}

int Node::rank() {
    int rank = 0;

    auto leftRank = this->_rank(this->left, rank);
    auto rightRank = this->_rank(this->right, rank);
    return leftRank < rightRank ? leftRank : rightRank;
}
