#ifndef _WURFTRAINER_HPP
#define _WURFTRAINER_HPP

#include <iostream>
#include "trainer.hpp"

class WurfTrainer : public Trainer{
    public:
        WurfTrainer(std::string str, char l) : Person(str), Trainer(str, l){}
        virtual void print(){std::cout<<name<<" (Wurf Trainer), "<<licence<<" Licence"<<std::endl;}

};

#endif