#include <iostream>

#include "Leftist.hpp"

int main(int argc, char* argv[]) {
    Leftist lh;


    lh.Insert(5);
    lh.PreOrder();
    lh.Insert(2);
    lh.PreOrder();
    lh.Insert(7);
    lh.PreOrder();
    lh.Insert(10);
    lh.PreOrder();
    lh.Insert(6);
    lh.PreOrder();
    lh.Insert(8);
    lh.PreOrder();
    lh.Insert(3);
    lh.PreOrder();
    lh.Insert(6);
    lh.PreOrder();
    lh.Insert(2);
    lh.PreOrder();
    std::cout << "Exiting\n";
}
