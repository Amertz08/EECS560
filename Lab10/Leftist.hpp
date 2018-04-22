#ifndef EECS560_LEFTIST_HPP
#define EECS560_LEFTIST_HPP

#include "Heap.hpp"

class Leftist : public Heap {
private:
    void _concat(Node* leftHeap, Node* rightHeap) override;
    bool _shouldSwap(Node* target) override;

public:
    Leftist();
    ~Leftist() override;

    void Insert(int value) override;
    void DeleteMin() override;
    int FindMin() override;
    void InOrder() override;
    void LevelOrder() override;

};


#endif //EECS560_LEFTIST_HPP
