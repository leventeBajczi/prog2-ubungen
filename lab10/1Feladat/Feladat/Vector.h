#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

// Egy dynamisches Array
template<class T>
class Vector
{
private:
	// Arraygr�sse
	unsigned int elementNum;
	// Pointer auf dyn. Speicherbereich
	T *pData;

	// Ausgabeoperator (friend-Deklaration)
	template<class Temp> friend std::ostream & operator << (std::ostream& os,const Vector<Temp>& v);

public:
	// Konstruktorok, destruktor
	Vector() {elementNum = 0;pData = 0;}
	Vector(const Vector& theOther);
	~Vector() { delete [] pData; }
	
	// Vectorgr�sse abfragen
	int  size()const{return elementNum;}
	// Vector entleeren
	void clear();
	// Ein Element entfernen. Indizen zwischen 0 �s size()-1 sind g�ltig
	void erase(unsigned int position);
	// Liefert das Element mit dem angegebenen Index (Element modifizierbar)
	// Indizen zwischen 0 �s size()-1 sind g�ltig
	T& at(unsigned int position);
	// Liefert das Element mit dem angegebenen Index (Element nur lesbar)
	// Indizen zwischen 0 �s size()-1 sind g�ltig
	const T& at(unsigned int position)const;
	// Ein Element einf�gen
	// Wenn Index gr�sser ist als Arraygr�sse erm�glichte Indizen,
	// Array soll vergr�ssert werden und restlichen Positionen mit 0 aufgef�llt werden
	bool insert(unsigned int position, T element);

	// Operator=
	const Vector& operator= (const Vector & theOther);

	// Indexierungsoperatoren (Member-Funktion at() als Operator)
	T& operator [](unsigned int position);
	const T& operator [](unsigned int position)const;
};

// Deklaration der Ausgabefunktion
template<class T>
std::ostream & operator << (std::ostream& os, const Vector<T>& v);
#endif /*VECTOR_H */


#include <limits.h>
#include <assert.h>

using namespace std;
template<class T>
ostream & operator << (ostream& os, const Vector<T> &v)
{
	for(unsigned int i=0;i<v.elementNum;i++)
	{
		os<<' '<<v.at(i);
	}
	return os;
}
template<class T>
Vector<T>::Vector(const Vector<T>& theOther)
{
	pData=NULL;
	*this=theOther;
}
template<class T>
void Vector<T>::clear()
{
	delete[]pData;
	pData=NULL;
	elementNum=0;
}


template<class T>
void Vector<T>::erase(unsigned int position)
{
	assert(position<elementNum);
	
	if(elementNum==1)
	{
		delete []pData;
		pData=NULL;
		elementNum=0;
		return;
	}

	elementNum--;
	T* pTemp=new T[elementNum];

	for(unsigned int i=0, j=0;i<elementNum+1;i++,j++)
	{
		if(i==position)
		{
			j--;
		}
		else
		{
			pTemp[j]=pData[i];
		}
	}
	delete[] pData;
	pData=pTemp;
}
template<class T>
T& Vector<T>::at(unsigned int position)
{
	assert(position<elementNum);
	return pData[position];
}
template<class T>
const T& Vector<T>::at(unsigned int position)const
{
	assert(position<elementNum);
	return pData[position];
}
template<class T>
bool Vector<T>::insert(unsigned int position, T element)
{
	if(elementNum==UINT_MAX)
	{
		return false;
	}
	
	T* pTemp=NULL;
	if(position<elementNum)
	{
		pTemp=new T[elementNum+1];
		for(unsigned int i=0, j=0; i<elementNum;i++,j++)
		{
			if(j==position)
			{
				pTemp[position]=element;
				i--;
			}
			else
			{
				pTemp[j]=pData[i];
			}
		}
		elementNum++;
	}
	else
	{
		pTemp=new T[position+1];
		for(unsigned int i=0;i<position;i++)
		{
			if(i<elementNum)
			{
				pTemp[i]=pData[i];
			}
			else
			{
				pTemp[i]=0;
			}
		}
		pTemp[position]=element;
		elementNum=position+1;
	}
	delete[]pData;
	pData=pTemp;
	return true;
}
template<class T>
T& Vector<T>::operator [](unsigned int position)
{
	return at(position);
}

template<class T>
const T& Vector<T>::operator [](unsigned int position)const
{
	return at(position);
}

template<class T>
const Vector<T>& Vector<T>::operator= (const Vector & theOther)
{
	assert(this!=&theOther);
	delete[]pData;
	if(theOther.elementNum==0)
	{
		elementNum=0;
		pData=NULL;
	}
	else
	{
		elementNum=theOther.elementNum;
		pData=new int[elementNum];
		for(unsigned int i=0;i<elementNum;i++)
		{
			pData[i]=theOther.pData[i];
		}
	}
	return *this;
}