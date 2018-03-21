#ifndef _DISPLAY_H
#define _DISPLAY_H


#include "Equipment.h"

class Display : public Equipment
{
    private:
        unsigned int age;
    public:
        void setAge(unsigned int a){age = a;}
        unsigned int getAge(){return age;}
        Display(unsigned int price, unsigned int sNum, unsigned int age) : Equipment(price, sNum) {
            setAge(age);
        }  
        void print()
        {
            std::cout<<"SNo: "<<getSnum()<<", price: "<<getPrice()<<"HUF";
            std::cout<<", age: "<<getAge();
        }
};


#endif