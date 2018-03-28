#ifndef OLIMPIKON_HPP
#define OLIMPIKON_HPP
#include <iostream>
using namespace std;

#include "person.hpp"

class Olimpikon : virtual public Person{
    protected:
        int best;
    public:
        int getBest(){return best;}
        void setBest(int best){this->best=best;}
        Olimpikon(const char* name, int year, int best) : Person(name, year){this->best = best;}
        virtual void print(){Person::print(); cout << " (Olimpikon)";}
        ~Olimpikon(){cout<<endl<<"olimpikon destructor is being called";}
        
};


#endif