#ifndef EECS560_MINMAXHEAP_HPP
#define EECS560_MINMAXHEAP_HPP

#include "Heap.hpp"

class MinMaxHeap : public Heap {
private:
    bool _isMinNode(int index) override;

public:
    MinMaxHeap();
};


#endif //EECS560_MINMAXHEAP_HPP
