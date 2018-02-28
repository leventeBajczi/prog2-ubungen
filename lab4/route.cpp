#include "route.hpp"

#include <cstring>
#include <iostream>

const char ROUTE[] = "Route";

unsigned int Route::counter = 0; 

Route::Route(const char* name)
{
    this->name = new char[strlen(name) + 1];
    this->points = NULL;
    strcpy(this->name, name);
    this->pointNum = 0;
}

Route::Route()
{
    this->name = new char[strlen(ROUTE) + 3];
    sprintf(this->name, "%s%02d", ROUTE, Route::counter);
    Route::counter++;
    this->points = NULL;
    this->pointNum = 0;
}

void Route::print()
{
    if(this->pointNum == 0)std::cout << this->name << " ist leer" << std::endl;
    else
    {
        std::cout<<this->name<<":\t"<<std::endl;
        for(int i = 0; i<this->pointNum; i++){
            std::cout<<"\t"<<(this->points)[i].lat()<<", "<<(this->points)[i].lon()<<std::endl;
        }
    }
}

void Route::rename(const char* name)
{
    delete [] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Route::~Route()
{
    delete [] this->name;
    delete [] this->points;
}

void Route::append(const Position& pos)
{
    Position* new_points = new Position[this->pointNum + 1];
    for(int i = 0; i<this->pointNum; i++)
    {
        new_points[i] = points[i];
    }
    new_points[this->pointNum] = pos;
    this->pointNum++;
    
    delete [] points;
    this->points = new_points;
}

void Route::overwrite(unsigned int index, const Position& pos)
{
    if(index<this->pointNum) points[index] = pos;
}

Route::Route(const Route &obj)
{
    this->name = new char[strlen(obj.name)];
    strcpy(this->name,obj.name);
    this->points = new Position[obj.pointNum];
    this->pointNum = obj.pointNum;
    for(int i = 0; i<this->pointNum; i++)
    {
        memcpy(&(this->points)[i], &(obj.points)[i], sizeof(Position));
    }
}

double Route::length()
{
    double len = 0.0;
    for(int i = 1; i<this->pointNum; i++)
    {
        len += getDistance((this->points)[i], (this->points)[i-1]);
    }
    return len;
}