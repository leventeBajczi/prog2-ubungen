#include <stdio.h>
#include <stdlib.h>
#include "baum.h"


int Baum_Add(Knote **Head, int Data)
{
    Knote *p = *Head;

    if (*Head == NULL){
        *Head = (Knote*) malloc(sizeof(Knote));
        (*Head)->Data = Data;
        (*Head)->Anzahl = 1;
    	(*Head)->Left = (*Head)->Right = NULL;
    	return 1;
    }
    else{
    	if (p->Data > Data) Baum_Add(&(p->Right), Data);
    	else if (p->Data < Data) Baum_Add(&(p->Left), Data);
    	else if (p->Data == Data) (p->Anzahl)++; 
    }
	return 0;
}

void Baum_Print(Knote *Head)
{
	if (Head == NULL){ 
		printf("Baum ist Leer!\n"); 
		return;
	}

	if(Head->Right)	Baum_Print(Head->Right);
	printf("Data: %d, Anzahl: %d\n", Head->Data, Head->Anzahl);
	if(Head->Left)	Baum_Print(Head->Left);
    
	return;
}

int Baum_Min(Knote *Head)
{
    while (Head->Right != NULL) Head = Head->Right;
    return Head->Data;
}

int Baum_Max(Knote *Head)
{
    while (Head->Left != NULL) Head = Head->Left;
    return Head->Data;
}

void Baum_Delete(Knote **Head)
{
    if ((*Head)->Right)	Baum_Delete(&((*Head)->Right));
    if ((*Head)->Left)	Baum_Delete(&((*Head)->Left));
    free(*Head);
    *Head = NULL;
    return;
}