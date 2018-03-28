#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

#define DONE 0

// Dynamisches Array
class Vector
{
	// Arraygroesse
	unsigned int elementNum;
	// Pointer auf Daten
	int *pData;

	// *Globale* Ausgabefunktion auf ostream (zur Diagnose), nur *friend-Deklaration* an dieser Stelle
	friend std::ostream& operator<<(std::ostream& os, const Vector& v);

public:
	// Konstruktoren, Destruktror
	Vector() : elementNum(0), pData(0) { }
	~Vector() {delete [] pData;}
	
	// Gibt die Groesse des Arrays an
	int size() const { return elementNum; }

#if DONE >= 1
	// Array entleeren
	void clear();

	// Neues Element in eine bestimmte Position einfügen.
	// Wenn das gegebene Position größer ist als das Array, das Array soll entsprechend
	// vergrößert werden. Die neuen Stellen sollen mit Nullen aufgefüllt werden.
	bool insert(unsigned int position, int element);
#endif

#if DONE >= 2
	// Gibt eine Referenz auf Element in Position "position"
	// Das Element is modifizierbar (kann L-Wert sein)
	// Indizen zwischen 0 und size()-1 sind gültig.
	int& at(unsigned int position);

	// Gibt eine Referenz auf Element in Position "position" (konstante Member-Fkt.)
	// Das Element is NICHT modifizierbar (kann nur R-Wert sein)
	// const Referenz (hier für int bringt nichts, aber für größeren Objekten vorteilhaft
	// gegenüber Wertrückgabe, siehe Hausaufgabe)
	const int& at(unsigned int position) const;
#endif

#if DONE >= 3
	// Kopierkonstruktor
	Vector(const Vector &theOther);
	// Operator= (Zuweisungsoperator)
	Vector& operator= (const Vector & theOther);
#endif

#if DONE >= 4
	// Entfernt ein Element an Position "position". Indizen zwischen 0 und size()-1 sind gültig.
	void erase(unsigned int position);
#endif

#if DONE >= 5
	// Zwei Formen von operator[]. 
	// Eigentlich übereinstimmen mit den at()-Funktionen, nur in Operatorform
	int & operator [](unsigned int position);
	const int & operator [](unsigned int position) const;
#endif
};

// Ausgabefunktion; das ist auch nur eine Deklaration
std::ostream& operator<<(std::ostream &os, const Vector &v);

#endif /*VECTOR_H */
