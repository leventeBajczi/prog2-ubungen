#ifndef OLIMPIKONHALLGATO_HPP
#define OLIMPIKONHALLGATO_HPP

#include<iostream>
using namespace std;

#include "olimpikon.hpp"
#include "hallgato.hpp"

class OlimpikonHallgato : public Hallgato, public Olimpikon{
    public:
        OlimpikonHallgato(const char* name, int year, int best, double avg) : Hallgato(name, year, avg), Olimpikon(name, year, best), Person(name, year){}
        virtual void print(){Person::print(); cout << " (OlimpikonHallgato)";}
        ~OlimpikonHallgato(){cout<<endl<<"olimpikonhallgato destructor is being called";}
        
};



#endif