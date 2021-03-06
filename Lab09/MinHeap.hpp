#ifndef EECS560_MINHEAP_HPP
#define EECS560_MINHEAP_HPP

#include "KHeap.hpp"

class MinHeap : public KHeap{
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
     * Min K-Heap
     * @param k
     */
    explicit MinHeap(int k);

    /**
     * Destructor
     */
    ~MinHeap() override;

    /**
     * Delete min value in heap
     */
    void DeleteMin() override;

    /**
     * Delete max value in heap
     */
    void DeleteMax() override;

};


#endif //EECS560_MINHEAP_HPP
