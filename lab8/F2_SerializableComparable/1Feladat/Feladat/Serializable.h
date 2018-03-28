#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>

class Serializable
{
public:
	virtual void Save(std::ostream &)=0;
	virtual void Load(std::istream &)=0;
};

#endif // SERIALIZABLE_H
