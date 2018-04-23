#ifndef EECS560_HEAP_HPP
#define EECS560_HEAP_HPP

#include <list>

#include "Node.hpp"

class Heap {
protected:
    Node* _root;

    virtual bool _shouldSwap(Node* target) = 0;

    bool _empty();
    void _swap(Node* target);
    void _delete(Node* target);
    void _concat(Node* leftHeap, Node* rightHeap);
    void _preOrder(Node* target);
    void _inOrder(Node* target, std::list<int>* l);
    int _height(Node* n);
    void _printLvl(Node* n, int lvl);

public:
    Heap();
    virtual ~Heap();
    void Insert(int value);
    void DeleteMin();
    int FindMin();
    void LevelOrder();
    void InOrder();
    void PreOrder();
    void BuildHeap(std::string fileName);
    int Height();
};


#endif //EECS560_HEAP_HPP
