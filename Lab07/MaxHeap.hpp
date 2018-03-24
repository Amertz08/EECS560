#ifndef EECS560_MAXHEAP_HPP
#define EECS560_MAXHEAP_HPP

#define HEAP_SIZE 500

class MaxHeap {

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
    bool _compare(int parent, int child);

    /**
     * Finds parent index for given node index
     * @param index : node index
     * @return parent index
     */
    int _parentIndex(int index);

    /**
     * Recurse up heap swapping values as needed
     * @param index : start index
     */
    void _upHeap(int index);

    /**
     * Recurse down heap finding new min
     * @param index : start index
     */
    void _downHeap(int index);

    /**
     * Prints node value and children values
     * @param index : node index to print
     */
    void _printNode(int index);

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
    int _minIndex();

    /**
     * Returns index of max value
     * @return
     */
    int _maxIndex();

public:
    /**
     * Min5 heap class
     */
    MaxHeap();

    /**
     * Deconstructor
     */
    ~MaxHeap();

    /**
     * Heapifies heap
     */
    void BuildHeap();

    /**
     * Inserts value into heap
     * @param value
     */
    void Insert(int value);

    /**
     * Adds value to next available spot
     * @param value
     */
    void Push(int value);

    /**
     * Prints the heap in index order
     */
    void Print();

    /**
     * Returns min value of heap
     * @return
     */
    int FindMin();

    /**
     * Returns max value of heap
     * @return
     */
    int FindMax();

    /**
     * Delete min value in heap
     */
    void DeleteMin();

    /**
     * Delete max value in heap
     */
    void DeleteMax();

    /**
     * Prints level order
     */
    void LevelOrder();
};


#endif //EECS560_MAXHEAP_HPP
