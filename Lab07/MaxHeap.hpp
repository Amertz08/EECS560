#ifndef EECS560_MAXHEAP_HPP
#define EECS560_MAXHEAP_HPP

#include "KHeap.hpp"

class MaxHeap : public KHeap {

private:

    /**
     * Looks at value of parent and child and
     * determines if they should be swapped
     * @param parent
     * @param child
     * @return
     */
    bool _compare(int parent, int child) override;

    /**
     * Recurse down heap finding new min
     * @param index : start index
     */
    void _downHeap(int index) override;

    /**
     * Returns index of min value
     * @return
     */
    int _minIndex() override;

    /**
     * Returns index of max value
     * @return
     */
    int _maxIndex() override;

public:

    /**
     * Delete min value in heap
     */
    void DeleteMin() override;

    /**
     * Delete max value in heap
     */
    void DeleteMax() override;
};


#endif //EECS560_MAXHEAP_HPP
