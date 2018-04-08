#ifndef _TEAM_HPP
#define _TEAM_HPP

#include "person.hpp"

class Team{
    private:
        Person** list;
        unsigned int listSize;
    public:
        void hire(Person*);
        Team(){list = 0; listSize = 0;}
        void printteam();
        ~Team();
};

#endif