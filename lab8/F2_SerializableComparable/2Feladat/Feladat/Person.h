#ifndef PERSON_H
#define PERSON_H

#include "Comparable.h"
#include "Serializable.h"

class Person: public Serializable, public Comparable
{
private:	
	 double height;
	 double weight;
public:
	unsigned char age;

	Person(unsigned char age,double height, double weight);
	bool SetHeight(double height);
	double GetHeight(){return height;}

	bool SetWeight(double weight);
	double GetWeight(){return weight;}


	bool operator ==(const Comparable& theOther);
	bool operator <(const Comparable& theOther);
	void Save(std::ostream &);
	void Load(std::istream &);
};
#endif PERSON_H