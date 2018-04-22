#ifndef EECS560_HEAP_HPP
#define EECS560_HEAP_HPP

#include "Node.hpp"

#define DEBUG 1

class Heap {
protected:
    Node* _root;

    virtual bool _shouldSwap(Node* target) = 0;

    bool _empty();
    void _swap(Node* target);
    void _delete(Node* target);
    void _concat(Node* leftHeap, Node* rightHeap);
    void _preOrder(Node* target);

public:
    Heap();
    virtual ~Heap();
    void Insert(int value);
    void DeleteMin();
    int FindMin();
    void LevelOrder();

    void PreOrder();
};


#endif //EECS560_HEAP_HPP
