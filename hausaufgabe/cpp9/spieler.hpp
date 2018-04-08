#ifndef _SPIELER_HPP
#define _SPIELER_HPP

#include <iostream>
#include "person.hpp"

class Spieler : virtual public Person{
    protected:
        unsigned int rnummer;
    public:
        Spieler(std::string str, unsigned int rn) : Person(str), rnummer(rn){}
        virtual void print(){std::cout<<name<<" (Spieler), "<<rnummer<<std::endl;}

};

#endif