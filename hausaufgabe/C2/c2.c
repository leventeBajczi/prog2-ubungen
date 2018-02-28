#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Element der Liste
typedef struct Daten {
	char * Name;
	unsigned long Nummer;
	struct Daten * next;
} ListElem ;

// Funktiondeklarationen
// Laboraufgaben
ListElem * TelefonBuch_Add ( ListElem *Head , const char *Name , long Tnummer );
void TelefonBuch_Print ( ListElem * Head );
ListElem * TelefonBuch_Delete ( ListElem * Head );

// Hausaufgaben
long TelefonBuch_Find ( ListElem *Head , const char * Name );
ListElem * TelefonBuch_Loeschen ( ListElem *Head , const char * Name );
ListElem* new_record(const char*, long);

int main ()
{
	ListElem * Head = NULL ;
	long Tnum ;
	char NameSuche1 [] = " Vajta Laszlo ";
	char NameSuche2 [] = " Kovacs Laszlo ";
	puts (" Inhalt des Telefonbuches :");
	TelefonBuch_Print ( Head );
	puts (" ------------------------------------");
	Head = TelefonBuch_Add (Head , " Sujbert Laszlo ", 4633213);
	Head = TelefonBuch_Add (Head , " Nagy Lajos ", 4632225);
	Head = TelefonBuch_Add (Head , " Kovacs Peter ", 2568275);
	Head = TelefonBuch_Add (Head , " Vajta Laszlo ", 1223213);
	puts (" Inhalt des Telefonbuches :");
	TelefonBuch_Print ( Head );
	puts (" ------------------------------------");
	if (( Tnum = TelefonBuch_Find (Head , NameSuche1 )))
	{
		printf ("%s Gefunden & Geloscht !\n", NameSuche1 );
		Head = TelefonBuch_Loeschen (Head , NameSuche1 );
		printf (" Telefonnummer = %lu\n",Tnum );
	}
	else printf ("%s, Nicht gefunden !\n",NameSuche1 );
	puts (" Inhalt des Telefonbuches :");
	TelefonBuch_Print ( Head );
	puts (" ------------------------------------");
	if (( Tnum = TelefonBuch_Find (Head , NameSuche2 )))
	{
		printf ("%s Gefunden & Geloescht !\n", NameSuche2 );
		Head = TelefonBuch_Loeschen (Head , NameSuche2 );
		printf (" Telefonnummer = %lu\n", Tnum );
	}
	else printf ("%s nicht gefunden !\n", NameSuche2 );
	puts (" Inhalt des Telefonbuches :");
	TelefonBuch_Print ( Head );
	puts (" ------------------------------------");
	Head = TelefonBuch_Delete ( Head );
	puts (" Liste geloescht !");
	return 0;
}

//Laboruebungen

ListElem* TelefonBuch_Add(ListElem *Head, const char *Name, long Tnummer)
{
    ListElem* save = Head;
    if(!Head) return new_record(Name, Tnummer);
    else
    {
        while(Head->next)Head = Head->next;
        (Head)->next = new_record(Name, Tnummer);
    }
    return save;
}
void TelefonBuch_Print(ListElem *Head)
{
    int i = 0;
    while(Head)
    {
        printf("%02d.\tName: %s, Nummer: %lu\n", i+1, Head->Name, Head->Nummer );
        i++;
        Head=Head->next;
    }
}
ListElem* TelefonBuch_Delete(ListElem *Head)
{
    ListElem* hilfe;
    if(!Head)return Head;
    while(Head->next)
    {
        free(Head->Name);
        hilfe = Head;
        Head = Head->next;
        free(hilfe);
    }
    return NULL;
}


ListElem* new_record(const char* Name, long Tnummer)
{
        ListElem *newElem = (ListElem*)malloc(sizeof(ListElem));
        newElem->Name = (char*)malloc(sizeof(char)*strlen(Name));
        strcpy(newElem->Name, Name);
        newElem->Nummer=Tnummer;
        newElem->next=NULL;
        return newElem;
}

//Hausaufgabe


long TelefonBuch_Find ( ListElem *Head , const char * Name )
{
    while(Head)
    {
        if(!strcmp(Head->Name, Name))return Head->Nummer;
        Head = Head->next;
    }
    return 0;
}
ListElem * TelefonBuch_Loeschen ( ListElem *Head , const char * Name )
{
    ListElem *original = Head;
    ListElem *tmp;
    while(Head)
    {
        if(!strcmp(Head->Name, Name))
        {
            if(tmp){    //falls gefunden, aber nicht der erste Element
                tmp->next = Head->next;
                free(Head->Name);
                free(Head);
                return original;
            }
            else    //falls gefunden, und ist der erste Element
            {
                free(Head->Name);
                tmp = Head->next;
                free(Head);
                return tmp;
            }
        }
        tmp = Head;
        Head = Head->next;
    }
    return original;
}