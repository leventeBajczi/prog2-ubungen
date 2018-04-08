#ifndef _SPIELERTRAINER_HPP
#define _SPIELERTRAINER_HPP

#include <iostream>
#include "spieler.hpp"
#include "trainer.hpp"

class SpielerTrainer : public Spieler, public Trainer{
    public:
        SpielerTrainer(std::string str, unsigned int rn, char l) : Person(str), Spieler(str, rn), Trainer(str, l){}
        virtual void print(){std::cout<<name<<" (Spieler und Trainer), "<<rnummer<<", "<<licence<<" Licence"<<std::endl;}

};

#endif