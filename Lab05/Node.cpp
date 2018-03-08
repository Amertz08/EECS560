#include <iostream>
#include "Node.hpp"

Node::Node() {
    this->_key = -1;
    this->_tag = false;
    this->_first = nullptr;
    this->_second = nullptr;
    this->_third = nullptr;
    this->_parent = nullptr;
    this->_minSecond = -1;
    this->_minThird = -1;
}

Node::Node(int value) {
    this->_tag = true;
    this->_key = value;
    this->_first = nullptr;
    this->_second = nullptr;
    this->_third = nullptr;
    this->_parent = nullptr;
    this->_minSecond = -1;
    this->_minThird = -1;
}

Node::~Node() {
    this->_parent = nullptr;
    this->_first = nullptr;
    this->_second = nullptr;
    this->_third = nullptr;
}

bool operator<(const Node &left, const Node &right) { return left._key < right._key; };
bool operator==(const Node &left, const Node &right) { return left._key == right._key; };
bool operator!=(const Node &left, const Node &right) { return left._key != right._key; };
bool operator>(const Node &left, const Node &right) { return left._key > right._key; }
bool operator>=(const Node &left, const Node &right) { return left._key >= right._key; }
bool operator<=(const Node &left, const Node &right) { return left._key <= right._key; }

bool Node::IsLeaf() { return this->_tag; }

bool Node::IsTwo() { return (!this->_tag && this->_first && this->_second && !this->_third); }

bool Node::IsThree() { return (!this->_tag && this->_first && this->_second && this->_third); }

int Node::GetKey() { return this->_key; }

void Node::SetParent(Node *p) { this->_parent = p; }

void Node::SetFirst(Node *p) {
    this->_first = p;
    if (p)
        p->SetParent(this);
}

void Node::SetSecond(Node *p) {
    this->_second = p;
    if (p)
        p->SetParent(this);
}

void Node::SetThird(Node *p) {
    this->_third = p;
    if (p)
        p->SetParent(this);
}

void Node::SetMinSecond(int value) { this->_minSecond = value; }

void Node::SetMinSecond(Node *n) { this->_minSecond = n->GetKey(); }

void Node::SetMinThird(int value) { this->_minThird = value; }

void Node::SetMinThird(Node *n) { this->_minThird = n->GetKey(); }

int Node::GetMinSecond() { return this->_minSecond; }

int Node::GetMinThird() { return this->_minThird; }

Node* Node::GetParent() { return this->_parent; }

Node* Node::GetFirst() { return this->_first; }

Node* Node::GetSecond(){ return this->_second; }

Node* Node::GetThird(){ return this->_third; }

void Node::Print(const std::string name) {
    std::cout << "Node: " << name << std::endl;
    if (this->IsLeaf()) {
        std::cout << "type: leaf\n";
        std::cout << "key: " << this->_key << std::endl;
    } else {
        std::cout << "type: interior\n";
        std::cout << "minSecond: " << this->_minSecond << " minThird: " << this->_minThird << std::endl;
        if (this->_first) {
            if (this->_first->IsLeaf()) {
                std::cout << "first: " << this->_first->GetKey();
                std::cout << " second: " << this->_second->GetKey();
                std::cout << " third: ";
                if (this->_third) {
                     std::cout << this->_third->GetKey() << std::endl;
                } else {
                    std::cout << "nullptr\n";
                }
            } else {
                std::cout << "first: ";
                if (this->_first->IsTwo()) {
                    std::cout << "2 node ";
                } else {
                    std::cout << "3 node ";
                }
                std::cout << "second: ";
                if (this->_second->IsTwo()) {
                    std::cout << "2 node ";
                } else {
                    std::cout << "3 node ";
                }

                std::cout << "third: ";
                if (this->_third) {
                    if (this->_third->IsTwo()) {
                        std::cout << "2 node\n";
                    } else {
                        std::cout << "3 node\n";
                    }
                } else {
                    std::cout << "nullptr\n";
                }
            }
        }
    }
    std::cout << "end stats\n";
}
