#ifndef EECS560_HEAP_HPP
#define EECS560_HEAP_HPP

#include "Node.hpp"

class Heap {
protected:
    Node* _root;

    bool _empty();
    void _swap(Node* target);
    void _delete(Node* target);
    virtual void _concat(Node* leftHeap, Node* rightHeap) = 0;
    virtual bool _shouldSwap(Node* target) = 0;
    void _preOrder(Node* target);

public:
    virtual ~Heap();
    virtual void Insert(int value) = 0;
    virtual void DeleteMin() = 0;
    virtual int FindMin() = 0;
    virtual void InOrder() = 0;
    virtual void LevelOrder() = 0;

    void PreOrder();
};


#endif //EECS560_HEAP_HPP
