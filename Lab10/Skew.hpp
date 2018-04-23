#ifndef EECS560_SKEW_HPP
#define EECS560_SKEW_HPP

#include "Heap.hpp"

class Skew : public Heap {
private:
    bool _shouldSwap(Node* target) override;

public:
    Skew();
    ~Skew() override;
};


#endif //EECS560_SKEW_HPP
