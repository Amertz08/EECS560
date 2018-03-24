#ifndef EECS560_KHEAP_HPP
#define EECS560_KHEAP_HPP


class KHeap {
private:
    int* _heap;
    int _k, _size;

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
};


#endif //EECS560_KHEAP_HPP
