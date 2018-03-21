#ifndef _PRINTER_H
#define _PRINTER_H

#include "Equipment.h"

class Printer : public Equipment
{
    private:
        unsigned int cartPrice;
    public:
        void setCartPrice(unsigned int cp){cartPrice = cp;}
        unsigned int getCartPrice(){return cartPrice;}
        Printer(unsigned int price, unsigned int sNum, unsigned int cartPrice) : Equipment(price, sNum) {
            setCartPrice(cartPrice);
        }  
        void print()
        {
            std::cout<<"SNo: "<<getSnum()<<", price: "<<getPrice()<<"HUF";
            std::cout<<", cartridge price: "<<getCartPrice();
        }

};

#endif