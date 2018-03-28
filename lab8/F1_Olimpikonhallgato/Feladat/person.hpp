#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
        string name;
        int year;
    public:
        string getName(){return name;}
        int getYear(){return year;}
        void setName(string name){this->name = name;}
        void setYear(int year){this->year = year;}
        Person(const char* name, int year){this->name=name; this->year = year;}
        virtual void print() = 0;
        virtual ~Person(){cout<<endl<<"person destructor is being called";}
        
};

void Person::print()
{
    cout << name << " " << year;
}

#endif