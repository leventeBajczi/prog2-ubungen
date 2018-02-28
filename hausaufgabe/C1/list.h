#ifndef LIST_H
#define LIST_H

// Element der liste
typedef struct Daten {
    char *Name;
    unsigned long Nummer;
    struct Daten *next;
} ListElem;

// Funktiondeklarationen
ListElem* TelefonBuch_Add(ListElem *, const char *, long ); // Neue Eintrag zuf�gen
void TelefonBuch_Print(ListElem *);	// Inhalt des Telefonbuchs ausschreiben 
ListElem* TelefonBuch_Delete(ListElem *); // Telefonbuch loeschen
ListElem* new_record(const char*, long);

#endif // LIST_H

