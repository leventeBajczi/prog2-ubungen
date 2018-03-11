#include <iostream>

#include "buch.hpp"

int main()
{
    Buch buch1("Author1", "Titel1", 12);
    Buch* buch2 = new Buch("Author2", "Titel2", 13);
    char* buchTitel = new char[7];
    char* buchAuthor = new char[8]; 
    buch1.getAuthor(buchAuthor);
    buch1.getTitle(buchTitel);
    std::cout<<"Buch1: \n\t"<<buchAuthor<<":\t"<<buchTitel<<" ("<<buch1.getAnzahl()<<")"<<std::endl;
    buch2->getAuthor(buchAuthor);
    buch2->getTitle(buchTitel);
    std::cout<<"Buch2: \n\t"<<buchAuthor<<":\t"<<buchTitel<<" ("<<buch2->getAnzahl()<<")"<<std::endl;
    delete buch2;
    delete [] buchTitel;
    delete [] buchAuthor;
    return 0;
}