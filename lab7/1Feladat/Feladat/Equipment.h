#ifndef _EQUIPMENT_H
#define _EQUIPMENT_H

#include <iostream>

class Equipment{
    protected:
        unsigned int price;
        unsigned int snum;    
        void setSnum(unsigned int s){snum = s;}
    private:

    public:
        void setPrice(unsigned int p){price = p;}
        unsigned int getSnum(){return snum;}
        unsigned int getPrice(){return price;}
        Equipment(unsigned int p, unsigned int s)
        {
            setSnum(s);
            setPrice(p);
        }
        virtual void print()
        {
            std::cout<<"Derived type has no print() function.";
        }
};


#endif