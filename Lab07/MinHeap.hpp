#ifndef EECS560_MINHEAP_HPP
#define EECS560_MINHEAP_HPP

#define HEAP_SIZE 500

class MinHeap {
private:
    int* _heap;
    int _k, _size;

    void _buildHeap(int targetIndex);

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
     * Prints node value and children values
     * @param index : node index to print
     */
    void _printNode(int index);

    /**
     * Returns value of nth child of ith node
     * @param i : node index
     * @param n : nth child
     * @return value of nth child
     */
    int _nthChild(int i, int n);

public:
    /**
     * Min5 heap class
     */
    MinHeap();

    /**
     * Deconstructor
     */
    ~MinHeap();

    /**
     * Heapifies heap
     */
    void BuildHeap();

    /**
     * Inserts value into heap
     * @param value
     */
    void Insert(int value);

    void Push(int value);

    void Print();
};


#endif //EECS560_MINHEAP_HPP
