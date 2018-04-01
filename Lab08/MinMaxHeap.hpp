#ifndef EECS560_MINMAXHEAP_HPP
#define EECS560_MINMAXHEAP_HPP

#define HEAP_SIZE 500

class MinMaxHeap {
private:
    int _size;
    int* _heap;

    void _upHeap(int index);
    void _downHeap(int index);
    bool _isMinNode(int index);
    int _parentIndex(int index);
    bool _shouldSwap(int parentIndex, int index);
    void _printNode(int index);
    int _leftChild(int index);
    int _rightChild(int index);
    int _findMin(int index);
    int _findMax(int index);

public:
    MinMaxHeap();
    ~MinMaxHeap();

    void Push(int val);
    void Insert(int val);
    void Print();
    void BuildHeap();
};


#endif //EECS560_MINMAXHEAP_HPP
