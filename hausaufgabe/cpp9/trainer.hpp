#ifndef _TRAINER_HPP
#define _TRAINER_HPP

#include <iostream>
#include "person.hpp"

class Trainer : virtual public Person{
    protected:
        char licence;
    public:
        Trainer(std::string str, char l) : Person(str), licence(l){}
        virtual void print(){std::cout<<name<<" (Trainer), "<<licence<<" Licence"<<std::endl;}

};

#endif