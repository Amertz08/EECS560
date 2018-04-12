#ifndef EECS560_LEFTIST_HPP
#define EECS560_LEFTIST_HPP

#include "Heap.hpp"

class Leftist : public Heap {
private:
    void _insert(Node* leftHeap, Node* rightHeap);
    bool _shouldSwap(Node* target) override;

public:
    Leftist();
    ~Leftist() override;

    void BuildHeap() override;
    void Insert(int value) override;

};


#endif //EECS560_LEFTIST_HPP
