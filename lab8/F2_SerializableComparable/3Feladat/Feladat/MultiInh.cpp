#include "Person.h"
#include <fstream>
#include <string>

using namespace std;


class Saver
{
private:
    string outFileName;
    ofstream ofs;
public:
    Saver( string outFileName): outFileName(outFileName), ofs(outFileName.c_str())
    {
        if(!ofs) 
        {
            cerr<<"Error opening output file: " << outFileName << endl;            
        }
    }
    
    // Wir benötigen Referenz (polymorphe Behandlung)
    // Ein Pointer wäre auch gut, aber nicht elegant
    bool Save(Serializable &item) 
    {
        item.Save(ofs);
        return !ofs;
    }

    // Sollte nicht vom Benutzer aufgerufen werden, der Destruktor von ofs 
    // wird es automatisch freigeben
    void Close()
    {
        ofs.close();
    }

};


// Diese sind nur Deklarationen, die Quellcode steht nicht zur Verfügung
class Loader
{
private:
    string inFileName;
    ifstream ifs;
    
public:
    Loader(string inFileName):inFileName(inFileName),ifs(inFileName.c_str())
    {
        if(!ifs) 
        {
            cerr<<"Error opening input file: " << inFileName << endl;            
        }
    }
    
    // Wir benötigen Referenz (polymorphe Behandlung)
    // Ein Pointer wäre auch gut, aber nicht elegant
    bool Load(Serializable& item)
    {
        item.Load(ifs);
        return !ifs;
    }


    // Sollte nicht vom Benutzer aufgerufen werden, der Destruktor von ifs 
    // wird es automatisch freigeben
    void Close()
    {
        ifs.close();
    }

};


int main() 
{
    // Array initialisieren
    const unsigned maxPeople=4;    
    Person* people[maxPeople];

    people[0]=new Person(12, 100, 50);
    people[1]=new Person(30, 180, 85);
    people[2]=new Person(40, 182, 90);
    people[3]=new Person(40, 182, 90);

    // Kimentjük a tömböt egy fájlba.
    // !!! Lehet, hogy a HSZK-ban módosítani kell az elérési utat,
    // hogy legyen írási jog. !!!
    Saver saver("d:\\user\\data.txt");
    
    for(unsigned int i=0;i<maxPeople;i++)
    {
        // TODO: Funktion Save testen (mit Fehlerüberprüfung)
        
        
        // Inhalt zerstören, damit Funktion Load 
        // getestet werden kann
        people[i]->age=0;
        people[i]->SetHeight(20);
        people[i]->SetWeight(10);
    }
    saver.Close();


    Loader loader("d:\\user\\data.txt") ;
    for(unsigned int i=0;i<maxPeople;i++)
    {
        // TODO: Funktion Load testen (mit Fehlerüberprüfung)

    }

    // Ausgabe und Freigabe
    for(unsigned int i=0;i<maxPeople;i++)
    {
        people[i]->Save(cout); cout << endl;
        delete people[i];
    }

    return 0;
}

