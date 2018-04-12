#ifndef EECS560_HEAP_HPP
#define EECS560_HEAP_HPP

#include "Node.hpp"

class Heap {
protected:
    Node* _root;

    bool _empty();
    void _swap(Node* target);
    virtual bool _shouldSwap(Node* target) = 0;

public:
    Heap();
    virtual ~Heap() = 0;
    virtual void BuildHeap() = 0;
    virtual void Insert(int value) = 0;
    virtual void DeleteMin() = 0;
    virtual int FindMin() = 0;
    virtual static Heap* Concat(Heap* left, Heap* right) = 0;
    virtual void PreOrder() = 0;
    virtual void InOrder() = 0;
    virtual void LevelOrder() = 0;
};


#endif //EECS560_HEAP_HPP
