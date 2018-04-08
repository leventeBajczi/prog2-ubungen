#include "team.hpp"
#include <cstring>
#include <iostream>

void Team::printteam()
{
    if(listSize == 0)std::cout<<"Es gibt keine Angestellter"<<std::endl;
    for(unsigned int i = 0; i<listSize; i++)
    {
        (*(list[i])).print();
    }
}

void Team::hire(Person* p)
{
    Person** tmp = new Person*[listSize+1];
    memcpy(tmp, list, listSize*sizeof(Person*));
    tmp[listSize++] = p;
    delete [] list;
    list = tmp;
}

Team::~Team(){
    for(unsigned int i = 0; i<listSize; i++)
    {
        delete list[i];
    }
    delete [] list;
}