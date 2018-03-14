#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>

using namespace std;

enum Format{SHORT , FULL};

class Student
{
private: 
    const string Name;
	const string Neptun;
    double Durchschnitt;   
    
	static const double GeldFur5;  // 40000 HUF;

	static enum Format Typ; // Fuer operator <<
	static int InstanzCnt;
public:
    Student(const string Name, const string Neptun, const double ds): Name(Name) , Neptun(Neptun), Durchschnitt(ds) {InstanzCnt++;}
    ~Student() {InstanzCnt--;}
    
	static int GetInstanzes(){return InstanzCnt;}
	static void SetFormatShort(){ Typ = SHORT; } // Fuer operator << (Print funktion)
	static void SetFormatFull(){ Typ = FULL; } // Fuer operator << (Print funktion)

	static bool isValidNeptun(const string c); 
	// Soll entscheiden ob ein Neptunkode g�ltig ist: 
	// 6 Ziffern (Nur aus Buchstaben oder Nummern)

	bool isValidNeptun(); 
	//Soll entscheiden ob das Neptunkode des objektes g�ltig ist 
	
	friend ostream & operator<<(ostream &, Student &); // Print funktion
	friend istream & operator>>(istream &, Student **); // Einlese funktion
	
	double getGeld() {return this->Durchschnitt / 5.0 * Student::GeldFur5;}
};


#endif
	