#ifndef EECS560_MINMAXHEAP_HPP
#define EECS560_MINMAXHEAP_HPP

#define ROOT 1
#define HEAP_SIZE 500
#define DEBUG 0

class MinMaxHeap {
private:
    int _size;
    int* _heap;

    void _upHeap(int index);
    void _downHeap(int index);
    bool _isMinNode(int index);
    bool _isLeaf(int index);
    int _parentIndex(int index);
    bool _shouldSwap(int parentIndex, int index);
    void _printNode(int index);
    int _leftChildIndex(int index);
    int _rightChildIndex(int index);
    int _leftChild(int index);
    int _rightChild(int index);
    int _findMinIndexHelper(int index, int minIndex);
    int _findMinIndex(int index);
    int _findMaxIndexHelper(int index, int minIndex);
    int _findMaxIndex(int index);
    int _findMin(int index);
    int _findMax(int index);
    int _level(int index);

public:
    MinMaxHeap();
    ~MinMaxHeap();

    void Push(int val);
    void Insert(int val);
    void Print();
    void BuildHeap();
    void LevelOrder();
    int FindMin();
    int FindMax();
    void DeleteMin();
    void DeleteMax();
};


#endif //EECS560_MINMAXHEAP_HPP
