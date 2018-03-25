#include <iostream>
#include "bib.hpp"
#include "buch.hpp"

using namespace std;

int main()
{
    Buch Mybuch1("Karl May", "Winettou", 1);
    Buch Mybuch2("Mark Twain", "Tom Sayer", 1);
    Buch OmaBuch("Lev Tolstoi","Krieg und Frieden", 1);

    Bibliothek SzaboErvin;       // Leere Bibliothek
    Bibliothek Omikk;            // Leere Bibliothek
    Bibliothek MyBooks(Mybuch1); // Biblothek inizialisiert durch Mybuch1

    SzaboErvin.add(Mybuch1); // Ich schenke Mybuch1 an SzaboErvin Bibliothek
    MyBooks -= Mybuch1;      // Ich nehme Mybuch1 aus von meinem MyBooks Bibliothek
    SzaboErvin += OmaBuch;   //Ich schenke OmaBuch and SzaboErvin Bibliothek

    printBibliothek(SzaboErvin); // Alle Buecher im Bibliothek
                              // mit Author + Titel auf dem Bildschirm ausgeben.
    cout << MyBooks; // Alle Buecher im Bibliothek mit Author + Titel
                    //auf dem Bildschirm ausgeben.

    Omikk += SzaboErvin; // Omikk kauft alle Buecher von SzaboErvin,
                        // SzaboErvin wird Leer sein.

    return 0;
}