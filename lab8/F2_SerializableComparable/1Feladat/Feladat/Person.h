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

	Person(unsigned char age,double height, double weight) : height(height), weight(weight), age(age){}
	bool SetHeight(double height){this->height = height; return true;}
	double GetHeight(){return height;}

	bool SetWeight(double weight){this->weight = weight; return true;}
	double GetWeight(){return weight;}


	bool operator ==(const Comparable& theOther){return (height == ((Person*)&theOther)->height && weight == ((Person*)&theOther)->weight && age == ((Person*)&theOther)->age);}
	bool operator <(const Comparable& theOther){return height < ((Person*)&theOther)->height;}
	void Save(std::ostream & os){os<<height<<";"<<weight<<";"<<(int)age<<std::endl;}
	void Load(std::istream & is){int n; char c; is>>height>>c>>weight>>c>>n;age=n;}
};

#endif