#include "bib.hpp"

void Bibliothek::add(Buch b)
{
   vb.push_back(b);
}
void Bibliothek::operator-=(Buch& b)
{
    vb.remove(b);
}
void Bibliothek::operator+=(Buch& b)
{
    vb.push_back(b);
}
void Bibliothek::operator+=(Bibliothek& b)
{

    list<Buch>::iterator it;
    for(it = b.vb.begin(); it != b.vb.end(); it++)
    {
        vb.push_back(*it);
    }
    b.vb.clear();
}
void printBibliothek(Bibliothek& obj)
{
    list<Buch>::iterator it;
    for(it = obj.vb.begin(); it != obj.vb.end(); it++)
    {
        (*it).print();
    }
}

ostream& operator<<(ostream& os, Bibliothek& b)
{
    char* author = new char[40];
    char* titel = new char[100];
    list<Buch>::iterator it;
    for(it = b.vb.begin(); it != b.vb.end(); it++)
    {
        (*it).getAuthor(author);
        (*it).getTitle(titel);
        os<<author<<": "<<titel<<endl;
    }
    delete [] author;
    delete [] titel;
    return os;
}
