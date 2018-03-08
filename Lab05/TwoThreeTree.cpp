#include <iostream>
#include "TwoThreeTree.hpp"


TwoThreeTree::TwoThreeTree() { this->_root = nullptr; }

TwoThreeTree::~TwoThreeTree() = default;

void TwoThreeTree::Insert(int value) {
    auto newNode = new Node(value);
//    std::cout << "Inserting: " << newNode->GetKey() << std::endl;

    if (!this->_root) {
        this->_root = new Node(value);
    } else {
        // Only 1 Node in tree
//        std::cout << "Checking if value in tree already\n";
        if (this->_find(this->_root, newNode)) {
//            std::cout << "Value already in tree\n";
            return;
        }
//        std::cout << "Value not found in tree\n";

        if (this->_root->IsLeaf()) {
//            std::cout << "Root is leaf\n";
            auto prevRoot = this->_root;
            auto newRoot = new Node();
            this->_root = newRoot;

            if (*newNode < *prevRoot) {
//                std::cout << "new < root\n";
                newRoot->SetFirst(newNode);
                newRoot->SetSecond(prevRoot);
                newRoot->SetMinSecond(prevRoot);
            } else {
//                std::cout << "root < new\n";
                newRoot->SetFirst(prevRoot);
                newRoot->SetSecond(newNode);
                newRoot->SetMinSecond(newNode);
            }
        } else {
//            std::cout << "Root is not leaf\n";
            this->_insert(this->_root, newNode);
        }
    }
//    std::cout << "Exiting Insert\n";
}

void TwoThreeTree::_insert(Node *target, Node *newNode) {
    auto parent = target->GetParent();
    auto first = target->GetFirst();
    auto second = target->GetSecond();
    auto third = target->GetThird();

    if (target->IsThree()) {
//        std::cout << "Target is a 3 node\n";

        if (!first->IsLeaf()) {
//            std::cout << "Not at bottom level\n";
            if (newNode->GetKey() < target->GetMinSecond()) {
//                std::cout << "going down first\n";
                this->_insert(first, newNode);
            } else if (newNode->GetKey() < target->GetMinThird()) {
//                std::cout << "going down second\n";
                this->_insert(second, newNode);
            } else {
//                std::cout << "going down third\n";
                this->_insert(third, newNode);
            }
        } else {
            auto newFirst = new Node();
            auto newSecond = new Node();
            if (*newNode < *first) {
//                std::cout << "new < first\n";
                newFirst->SetFirst(newNode);
                newFirst->SetSecond(first);
                newFirst->SetMinSecond(first);
                newSecond->SetFirst(second);
                newSecond->SetSecond(third);
                newSecond->SetMinSecond(third);
            } else if (*newNode < *second) {
//                std::cout << "new < second\n";
                newFirst->SetMinSecond(newNode);
                newFirst->SetFirst(first);
                newFirst->SetSecond(newNode);
                newSecond->SetFirst(second);
                newSecond->SetSecond(third);
                newSecond->SetMinSecond(third);
            } else if (*newNode < *third) {
//                std::cout << "new < third\n";
                newFirst->SetFirst(first);
                newFirst->SetSecond(second);
                newFirst->SetMinSecond(second);
                newSecond->SetFirst(newNode);
                newSecond->SetSecond(third);
                newSecond->SetMinSecond(third);
            } else {
//                std::cout << "third < new\n";
                newFirst->SetFirst(first);
                newFirst->SetSecond(second);
                newFirst->SetMinSecond(second);
                newSecond->SetFirst(third);
                newSecond->SetSecond(newNode);
                newSecond->SetMinSecond(newNode);
            }
            if (parent) {
//                std::cout << "Parent exists\n";
                auto pSecond = parent->GetSecond();
                auto pThird = parent->GetThird();

                if (parent->IsThree()) {
                    // TODO: finish this
//                    std::cout << "PARENT IS THREE\n";
                } else {
//                    std::cout << "Parent is not three\n";

                    if (newNode->GetKey() < parent->GetMinSecond()) {
//                        std::cout << "at parent->first\n";
                        parent->SetFirst(newFirst);
                        parent->SetSecond(newSecond);
                        parent->SetMinSecond(newSecond);
                        parent->SetThird(pSecond);
                        parent->SetMinThird(pSecond);
                    } else {
//                        std::cout << "at parent->second\n";
                        parent->SetSecond(newFirst);
                        parent->SetMinSecond(newFirst->GetFirst());
                        parent->SetThird(newSecond);
                        parent->SetMinThird(newSecond->GetFirst());
//                    delete pSecond;
                    }

//                    parent->Print("parent");
//                    parent->GetFirst()->Print("parent->first");
//                    parent->GetSecond()->Print("parent->second");
//                    parent->GetThird()->Print("parent->third");
                }
            } else {
//                std::cout << "Parent does not exist i.e. at root\n";
                // Splitting root node
                auto newParent = new Node();
                this->_root = newParent;

                newParent->SetFirst(newFirst);
                newParent->SetSecond(newSecond);
                newParent->SetMinSecond(newSecond->GetFirst());
//                newParent->Print("newParent");
//                newParent->GetFirst()->Print("newParent->first");
//                newParent->GetSecond()->Print("newParent->second");
            }
            delete target;
        }
    } else if (target->IsTwo()) {
//        std::cout << "Target is 2 node\n";
        if (!first->IsLeaf()) {
//            std::cout << "Not at bottom level\n";
            if (newNode->GetKey() < target->GetMinSecond()) {
//                std::cout << "going down first\n";
                this->_insert(first, newNode);
            } else {
//                std::cout << "going down second\n";
                this->_insert(second, newNode);
            }
        } else {
            if (newNode->GetKey() < target->GetMinSecond()) {
//                std::cout << "new < minSecond\n";
                if (*newNode < *first) {
//                    std::cout << "new < first\n";
                    // newNode is new first
                    target->SetFirst(newNode);
                    target->SetSecond(first);
                    target->SetMinSecond(first);
                } else {
//                    std::cout << "first < new\n";
                    // newNode is new second
                    target->SetSecond(newNode);
                    target->SetMinSecond(newNode);
                }
//                std::cout << "Second is new third\n";
                // second shifts to third
                target->SetThird(second);
                target->SetMinThird(second);

            } else if (newNode->GetKey() < target->GetMinThird()) {
//                std::cout << "new < minThird\n";
                if (*newNode < *second) {
//                    std::cout << "new < second\n";
                    // newNode is the new second
                    target->SetSecond(newNode);
                    target->SetMinSecond(newNode);
                    target->SetThird(second);
                    target->SetMinSecond(second);
                } else {
//                    std::cout << "second < new\n";
                    // newNode is third
                    target->SetThird(newNode);
                    target->SetMinThird(newNode);
                }
            } else {
//                std::cout << "third < new\n";
                // third < newNode
                target->SetThird(newNode);
                target->SetMinThird(newNode);

//                target->Print("target");
            }
        }

    } else {
        // Node is leaf
        std::cout << "Should not be here\n";
        exit(1);
    }
//    std::cout << "Exiting _insert\n";
}

void TwoThreeTree::LevelOrder() {
    if (!this->_root) {
        std::cout << "Empty Tree\n";
        return;
    } else if (this->_root->IsLeaf()) {
        std::cout << this->_root->GetKey() << std::endl;
        return;
    }

    std::queue<Node*> q;
    auto target = this->_root;
    this->_levelOrder(target, &q);
    auto n = q.size();
    std::cout << "Values in queue: " << n << std::endl;
    for (int i = 0; i < n; i++) {
        auto val = q.front();
        std::cout << val->GetKey() << std::endl;
        q.pop();
    }
}

void TwoThreeTree::_levelOrder(Node *target, std::queue<Node*> *q) {
    auto first = target->GetFirst();
    auto second = target->GetSecond();
    auto third = target->GetThird();

    if (first) {
        if (first->IsLeaf()) {
//            std::cout << "Pushing first: " << first->GetKey() << std::endl;
            q->push(first);
        } else {
            this->_levelOrder(first, q);
        }
    }

    if (second) {
        if (second->IsLeaf()) {
//            std::cout << "Pushing second: " << second->GetKey() << std::endl;
            q->push(second);
        } else {
            this->_levelOrder(second, q);
        }
    }

    if (third) {
        if (third->IsLeaf()) {
//            std::cout << "Pushing third: " << third->GetKey() << std::endl;
            q->push(third);
        } else {
            this->_levelOrder(third, q);
        }
    }
}

Node* TwoThreeTree::Find(int value) {
    std::cout << "Looking for value: " << value << std::endl;
    if (!this->_root) {
        std::cout << "Empty tree. Value not found\n";
        return nullptr;
    }
    Node* ans = nullptr;
    auto valNode = new Node(value);

    if (this->_root->IsLeaf()) {
//        std::cout << "Root is leaf\n";
        if (*this->_root == *valNode) {
//            std::cout << "Value at root\n";
            ans = this->_root;
        }
    } else {
        ans = this->_find(this->_root, valNode);
    }
    delete valNode;
    return ans;
}

Node* TwoThreeTree::_find(Node *target, Node* value) {
    Node* ans = nullptr;
    auto first = target->GetFirst();
    auto second = target->GetSecond();
    auto third = target->GetThird();

    if (first) {
//        std::cout << "Looking at first\n";
        if (first->IsLeaf()) {
//            std::cout << "first is leaf: " << first->GetKey() << std::endl;
            if (*first == *value) {
//                std::cout << "Value: " << first->GetKey() << " found at first\n";
                ans = first;
            }
        } else {
//            std::cout << "first is not leaf\n";
            ans = this->_find(first, value);
        }
    }
//    std::cout << "Checked first\n";
    if (ans)
        return ans;


    if (second) {
//        std::cout << "Looking at second\n";
        if (second->IsLeaf()) {
//            std::cout << "second is leaf: " << second->GetKey() << std::endl;
            if (*second == *value) {
//                std::cout << "Value: " << second->GetKey() << " found at second\n";
                ans = second;
            }
        } else {
//            std::cout << "second is not leaf\n";
            ans = this->_find(second, value);
        }
    }
//    std::cout << "Checked second\n";
    if (ans)
        return ans;

    if (third) {
//        std::cout << "Looking at third\n";
        if (third->IsLeaf()) {
//            std::cout << "third is leaf: " << third->GetKey() << std::endl;
            if (*third == *value) {
//                std::cout << "Value: " << third->GetKey() << " found at third\n";
                ans = third;
            }
        } else {
//            std::cout << "third is not leaf\n";
            ans = this->_find(third, value);
        }
    }
//    std::cout << "Checked third\n";

    return ans;
}

Node* TwoThreeTree::FindMin() {
    if (!this->_root) {
        std::cout << "Empty tree\n";
        return nullptr;
    } else if (this->_root->IsLeaf()) {
        return this->_root;
    } else {
        Node* target = this->_root;
        return this->_findMin(target);
    }
}

Node* TwoThreeTree::_findMin(Node *target) {
    if (target->IsLeaf()) {
        return target;
    } else {
        return this->_findMin(target->GetFirst());
    }
}

Node* TwoThreeTree::FindMax() {
    if (!this->_root) {
        std::cout << "Empty tree\n";
        return nullptr;
    } else if (this->_root->IsLeaf()) {
        return this->_root;
    } else {
        Node* target = this->_root;
        return this->_findMax(target);
    }
}

Node* TwoThreeTree::_findMax(Node *target) {
    if (target->IsLeaf()) {
        return target;
    } else if (target->GetThird()) {
        return this->_findMax(target->GetThird());
    } else {
        return this->_findMax(target->GetSecond());
    }
}

void TwoThreeTree::DeleteMin() {
    auto target = this->FindMin();
    if (target) {
        auto parent = target->GetParent();
        auto second = parent->GetSecond();
        auto third = parent->GetThird();

        parent->SetFirst(second);
        parent->SetSecond(third);
        parent->SetMinSecond(third);
        parent->SetThird(nullptr);
        parent->SetMinThird(-1);
        delete target;
    }
}

void TwoThreeTree::DeleteMax() {
    auto target = this->FindMax();
    if (target) {
        auto parent = target->GetParent();
        auto second = parent->GetSecond();
        auto third = parent->GetThird();

        if (target == third) {
            parent->SetThird(nullptr);
            parent->SetMinThird(-1);
            delete target;
        } else {
            // TODO: implement
        }
    }
}

void TwoThreeTree::Delete(int value) {
    std::cout << "NOT IMPLEMENTED\n";
}