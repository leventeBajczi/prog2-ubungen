#ifndef _ROUTE_HPP
#define _ROUTE_HPP

#include "position.h"

class Route{
    private:
        char* name;
        Position *points;
        unsigned int pointNum;
        static unsigned int counter;
    public:
        Route();
        Route(const char*);
        ~Route();
        void rename(const char*);
        void print();
        void append(const Position&);
        void overwrite(unsigned int, const Position&);
        double length();
        Route(const Route& obj);
};

#endif