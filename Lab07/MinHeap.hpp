#ifndef EECS560_MINHEAP_HPP
#define EECS560_MINHEAP_HPP

#define HEAP_SIZE 500

class MinHeap {
private:
    int* _heap;
    int _k, _size;

    void _buildHeap(int targetIndex);
    int _parentIndex(int index);
    void _upHeap(int index);
    void _printNode(int index);
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
