#ifndef _PERSON_HPP
#define _PERSON_HPP

#include <string>

class Person{
    protected:
        std::string name;
    public:
        Person(std::string str) : name(str){}
        virtual ~Person(){}
        virtual void print() = 0;
};

#endif