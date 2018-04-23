#include <iostream>

#include "Heap.hpp"
#include "Leftist.hpp"
#include "Skew.hpp"

void TestTree(Heap* h, const std::string &type)
{
    std::cout << "TESTING " << type << std::endl;
    h->Insert(5);
    h->PreOrder();
    h->InOrder();
    h->Insert(2);
    h->PreOrder();
    h->InOrder();
    h->Insert(7);
    h->PreOrder();
    h->InOrder();
    h->Insert(10);
    h->PreOrder();
    h->InOrder();
    h->Insert(6);
    h->PreOrder();
    h->InOrder();
    h->Insert(8);
    h->PreOrder();
    h->InOrder();
    h->Insert(3);
    h->PreOrder();
    h->InOrder();
    h->Insert(6);
    h->PreOrder();
    h->InOrder();
    h->Insert(2);
    h->PreOrder();
    h->InOrder();
    std::cout << "Done inserting\n";

    std::cout << "DeleteMin\n";
    h->DeleteMin();
    h->PreOrder();
    h->InOrder();
    std::cout << "DeleteMin\n";
    h->DeleteMin();
    h->PreOrder();
    h->InOrder();

    auto min = h->FindMin();
    std::cout << "Min: " << min << std::endl;
    std::cout << "Exiting\n";
}

int main(int argc, char* argv[]) {
    Leftist lh;
    Skew sk;
    std::cout << "STARTING TEST PROGRAM\n";

    TestTree(&lh, "Leftist");
    TestTree(&sk, "Skew");
}
