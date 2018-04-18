#include "Vector.h"

using namespace std;

int main()
{
	Vector<int> v1;

	// Insert testen
	for(int i=1;i<10;i++)
	{
		v1.insert(i,i);
	}

	// Ausgabeoperator (operator<<) und Funktion at() testen
	cout<<v1<<endl;
	// Erwartete Ausgabe:
	// 0 1 2 3 4 5 6 7 8 9

	// Kopierkonstruktor
	Vector<int> v2(v1); // Oder: Vector v2=v1;
	// op=
	Vector<int> v3;
	v3=v2;
	
	// v1 verändern (erase testen)
	v1.erase(0);
	// v1.erase(9); // Das soll assert() auslösen

	cout<<endl<<v1<<endl<<v2<<endl<<v3<<endl;
	// Erwartete Ausgabe:
	// 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9

	v2.insert(0,-1);
	cout<<v2<<endl;
	// Erwartete Ausgabe:
	// -1 0 1 2 3 4 5 6 7 8 9

	v2.insert(10,-1);
	cout<<v2<<endl;
	// Erwartete Ausgabe:
	//  -1 0 1 2 3 4 5 6 7 8 -1 9

	v2.insert(12,-1);
	cout<<v2<<endl;
	// Erwartete Ausgabe:
	// -1 0 1 2 3 4 5 6 7 8 -1 9 -1

	v2.insert(15,-1);
	cout<<v2<<endl;
	// Erwartete Ausgabe:
	// -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -1

	v2[15]=-2;
	cout<<v2<<endl;
	// Erwartete Ausgabe:
	// -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -2

	// v2[16]=3; // Das soll assert() auslösen

	return 0;
}

