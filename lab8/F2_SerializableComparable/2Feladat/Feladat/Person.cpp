#include "Person.h"

using namespace std;

Person::Person(unsigned char age,double height, double weight)
{
	this->age=age;
	this->height=height;
	this->weight=weight;
}

bool Person::SetHeight(double height)
{
	if(height<10||height>300)
		return false;
	this->height=height;
		return true;
}


bool Person::SetWeight(double weight)
{
	if(weight<0||weight>400)
		return false;
	this->weight=weight;
		return true;
}


bool Person::operator ==(const Comparable& theOther)
{
	Person* pPerson=(Person*)&theOther;

	if(age==pPerson->age && height==pPerson->height && weight==pPerson->weight)
		return true;
	else
		return false;
}

bool Person::operator <(const Comparable& theOther)
{
	Person* pPerson=(Person*)&theOther;

	if(age>pPerson->age)
		return true;
	else
		return false;
}

void Person::Save(ostream & os)
{
		os<<(int)age<<';'<<height<<';'<<weight<<endl;
}

void Person::Load(istream &is)
{
	double height;
	double weight;
	int age;
	char c;

	is>>age;
	is>>c;
	if(c!=';')is.clear(ios::failbit);
	is>>height;
	is>>c;
	if(c!=';')is.clear(ios::failbit);
	is>>weight;
	
	if(is)
	{
		this->age=age;
		this->height=height;
		this->weight=weight;
	}
	else
	{
		cerr<<"Error in input format."<<endl;
	}
}