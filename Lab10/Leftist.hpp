#ifndef EECS560_LEFTIST_HPP
#define EECS560_LEFTIST_HPP

#include "Heap.hpp"

class Leftist : public Heap {
private:
    bool _shouldSwap(Node* target) override;

public:
    Leftist();
    ~Leftist() override;
};


#endif //EECS560_LEFTIST_HPP
