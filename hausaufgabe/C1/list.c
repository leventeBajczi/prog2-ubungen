#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        printf("%02d.\tName: %s, Nummer: %d\n", i+1, Head->Name, Head->Nummer );
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