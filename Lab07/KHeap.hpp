#ifndef EECS560_KHEAP_HPP
#define EECS560_KHEAP_HPP

#define MAX_HEAP_SIZE 500

class KHeap {
private:
    int* _heap;
    int _k, _size;

    /**
     * Looks at value of parent and child and
     * determines if they should be swapped
     * @param parent
     * @param child
     * @return
     */
    virtual bool _compare(int parent, int child) = 0;

    /**
     * Finds parent index for given node index
     * @param index : node index
     * @return parent index
     */
    int _parentIndex(int index);

    /**
     * Find index nth child index of ith node
     * @param i : target node
     * @param n : child number
     * @return child index
     */
    int _nthChildIndex(int i, int n);

    /**
     * Returns value of nth child of ith node
     * @param i : node index
     * @param n : nth child
     * @return value of nth child
     */
    int _nthChild(int i, int n);

    /**
     * Returns index of min value
     * @return
     */
    virtual int _minIndex() = 0;

    /**
     * Returns index of max value
     * @return
     */
    virtual int _maxIndex() = 0;

    /**
     * Recurse down heap finding new min or max
     * @param index : start index
     */
    virtual void _downHeap(int index) = 0;

public:

    /**
     * K-Heap inteface
     * @param k
     */
    KHeap(int k);

    /**
     * Destructor
     */
    ~KHeap();

    /**
     * Heapifies heap
     */
    void BuildHeap();
};


#endif //EECS560_KHEAP_HPP
