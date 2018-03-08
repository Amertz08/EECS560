#ifndef EECS560_TWOTHREETREE_HPP
#define EECS560_TWOTHREETREE_HPP

#include <queue>
#include "Node.hpp"

class TwoThreeTree {
private:
    Node* _root;
public:
    TwoThreeTree();
    ~TwoThreeTree();
    void Insert(int value);
    void _insert(Node* target, Node* newNode);
    void LevelOrder();
    void _levelOrder(Node* target, std::queue<Node*>* q);
    Node* Find(int value);
    Node* _find(Node* target, Node* value);
    Node* FindMin();
    Node* _findMin(Node* target);
    Node* FindMax();
    Node* _findMax(Node* target);
    void DeleteMin();
    void DeleteMax();
    void Delete(int value);
};


#endif //EECS560_TWOTHREETREE_HPP
