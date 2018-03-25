#ifndef _BIB_HPP
#define _BIB_HPP

#include "buch.hpp"
#include <iostream>
#include <list>
using namespace  std;

class Bibliothek{
    private:
        list<Buch> vb;
    public:
        
        Bibliothek() {};
        Bibliothek(Buch b){
            (*this).add(b);
        }
        void add(Buch);
        void operator-=(Buch&);
        void operator+=(Buch&);
        void operator+=(Bibliothek&);

        friend void printBibliothek(Bibliothek&);
        friend ostream& operator<<(ostream&, Bibliothek&);

};

#endif