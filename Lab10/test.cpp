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
    std::cout << "Done inserting\n";

    lh.DeleteMin();
    lh.PreOrder();
    lh.DeleteMin();
    lh.PreOrder();

    auto min = lh.FindMin();
    std::cout << "Min: " << min << std::endl;
    std::cout << "Exiting\n";
}
