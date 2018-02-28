#include "route.hpp"

#include <iostream>

int main()
{
    Route r1;
    r1.print();
    r1.append(Position(47.0, 19.0));
    r1.append(Position(47.0, 20.0));
    r1.print();
    std::cout<<"Length of r1: "<<r1.length()<<" m"<<std::endl;
    Route r2(r1);
    r2.print();
    r2.overwrite(1, Position(45.0, 45.0));
    r2.print();
    r1.print();
    return 0;
}