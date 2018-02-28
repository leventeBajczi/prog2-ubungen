#include "rectangle.hpp"
#include "circle.hpp"
#include "menge.hpp"

#include <iostream>

int main()
{
    Menge menge;
    menge.insert(1);
    menge.insert(3);
    menge.insert(5);

    std::cout << (menge.isElement(2) ? "yes" : "no") << std::endl;
    menge.print();


    return 0;
}