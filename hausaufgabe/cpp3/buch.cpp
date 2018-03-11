#include "buch.hpp"

Buch::Buch(const char* author, const char* titel, unsigned int anzahl)
{
    this->titel = new char[strlen(titel)+1];
    strcpy(this->titel, titel);
    strcpy(this->author, author);
    this->anzahl = anzahl;
}
void Buch::setTitel(const char* titel)
{
    delete [] this->titel;
    this->titel = new char[strlen(titel)+1];
    strcpy(this->titel, titel);
}

Buch::Buch(const Buch &obj){
    this->titel = new char[strlen(obj.titel)+1];
    strcpy(this->titel, obj.titel);
    strcpy(this->author, obj.author);
    this->anzahl = obj.anzahl;
}