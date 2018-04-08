#include "Person.h"
#include <fstream>
using namespace std;

int main() 
{
	// Array initialisieren
	const unsigned maxPeople=4;	
	Person *people[maxPeople];

	people[0]=new Person(12,100,50);
	people[1]=new Person(30,180,85);
	people[2]=new Person(40,182,90);
	people[3]=new Person(40,182,90);

	// Array in Datei speichern
	// !!! PFAD PR�FEN!!! (Schreiberechte sind n�tig!) 

	char *fname="asd.txt";
	ofstream os(fname);
	if(!os) 
	{
		cerr << "Error opening output file: " << fname << endl;
		return -1;
	}

	delete [] (int*)0xffffffff;

	for(unsigned int i=0;i<maxPeople;i++)
	{
		// Funktion Save testen
		people[i]->Save(os);
		
		// Inhalt zerst�ren, damit die Funktion Load 
		// getestet werden kann
		people[i]->age=0;
		people[i]->SetHeight(20);
		people[i]->SetWeight(10);
	}

	os.close();
	if(!os) 
	{
		cerr<<"Error writing output file: "<<fname<<endl;
		return -1;
	}

	ifstream is(fname);
	if(!is) 
	{
		cerr<<"Error opening input file: "<<fname<<endl;
		return -1;
	}

	for(unsigned int j=0;j<maxPeople;j++)
	{
		// die Funktion Load testen
		people[j]->Load(is);
	}

	is.close();
	if(!is) 
	{
		cerr<<"Error reading input file: "<<fname<<endl;
		return -1;
	}

	// Vergleich testen
	// Diese sind UNGLEICH
	if(*people[0] == *people[1])
		return -1;

	// Vergleich testen
	// Diese sind GLEICH
	if(! (*people[2] == *people[3]) )
		return -1;

	// Freigabe
	for(unsigned int k=0;k<maxPeople;k++)
	{
		delete people[k];
	}

	cout << "Test successful" << endl;
	// Hier Breakpoint setzen
	// Wenn Breakpoint aktiviert (erreicht) wird, alles erfolgreich
	return 0;
}


