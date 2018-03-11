#ifndef _BUCH_HPP
#define _BUCH_HPP

#include <cstring>

class Buch{
    private:
        char author[40];
        char *titel;
        unsigned int anzahl;
    public:
        Buch(const char*, const char*, unsigned int);
        void setAuthor(const char* author){ strcpy(this->author, author);}
        void setTitel(const char*);
        void setAnzahl(unsigned int anzahl){ this-> anzahl = anzahl;}

        void getAuthor(char* author){ strcpy(author, this->author);}        //falls eine pointer zurückgegeben wäre, wären die Privateigenschaften modizifierbar
        void getTitle(char* titel){ strcpy(titel, this->titel);}
        unsigned int getAnzahl(){ return this-> anzahl;}

        ~Buch(){ delete [] titel;}

        /* Überlegen Sie, ob die Klasse einen Kopierkonstruktor braucht. Begründen Sie!

            Ja - dynamische Speicherplatz ist benutzt, und das führt dazu dass eine sogenannte "Shallow-Copy" ist nicht für uns genug, 
            weil das nur die Addresse des Speicherbedarfes kopieren würde.
        */        
        Buch(const Buch &obj);   
};

#endif