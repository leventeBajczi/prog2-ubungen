#ifndef COMPARABLE_H
#define COMPARABLE_H


class Comparable
{
public:
	virtual bool operator ==(const Comparable& )=0;
	virtual bool operator <(const Comparable& )=0;
};

#endif //COMPARABLE_H