#ifndef _COMPUTER_H
#define _COMPUTER_H


#include "Equipment.h"

class Computer : public Equipment
{
    private:
        unsigned int thing;
    public:
        void setThing(unsigned int t){thing = t;}
        unsigned int getThing(){return thing;}
        Computer(unsigned int price, unsigned int sNum, unsigned int t) : Equipment(price, sNum) {
            setThing(t);
        }  
        void print()
        {
            std::cout<<"SNo: "<<getSnum()<<", price: "<<getPrice()<<"HUF";
            std::cout<<", thing: "<<getThing();
        }
};


#endif