#ifndef EECS560_MINMAX_HPP
#define EECS560_MINMAX_HPP

#define ROOT 1
#define MAX_SIZE 500

class MinMax {
private:
    int* heap;
    int size;

    bool isMinNode(int i);
    int parentIndex(int i);
    int parent(int i);
public:
    MinMax();
    ~MinMax();

    void Push(int value);

};


#endif //EECS560_MINMAX_HPP
