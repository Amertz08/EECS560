#ifndef EECS560_MAXMINHEAP_HPP
#define EECS560_MAXMINHEAP_HPP

#include "Heap.hpp"

class MaxMinHeap : public Heap {
private:
    bool _isMinNode(int index) override;

public:
    MaxMinHeap();
};


#endif //EECS560_MAXMINHEAP_HPP
