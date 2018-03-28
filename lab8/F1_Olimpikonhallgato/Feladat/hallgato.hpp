#ifndef HALLGATO_HPP
#define HALLGATO_HPP

#include<iostream>
using namespace std;

#include "person.hpp"


class Hallgato : virtual public Person{
    protected:
        double avg;
    public:
        double getAvg(){return avg;}
        void setAvg(double avg){this->avg=avg;}
        Hallgato(const char* name, int year, double avg) : Person(name, year){this->avg = avg;}
        virtual void print(){Person::print(); cout << " (Hallgato)";}
        ~Hallgato(){cout<<endl<<"hallgato destructor is being called";}
};



#endif