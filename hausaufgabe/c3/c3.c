#include<stdio.h>
#include <stdlib.h>

// Element des Baumes
typedef struct Messung {
	int Data;
	int Anzahl;
	struct Messung *Right, *Left;
} Knote;

// Funktiondeklarationen
// Laboraufgaben
int Baum_Add ( Knote** Head , int Data );
void Baum_Print ( Knote* Head );
int Baum_Min ( Knote* Head );
int Baum_Max ( Knote* Head );
void Baum_Delete ( Knote** Head );

// Hausaufgaben
int Baum_Find ( Knote *Head , int Data );
double Baum_Avg ( Knote * Head );

int main ()
{
	Knote * Head = NULL ;
	int DataMin , DataMax ;
	int Gesucht = 3;
	Baum_Print ( Head );
	puts (" ------------------------");
	puts (" Baum wird Aufgebaut !");
	Baum_Add (& Head , 2);
	Baum_Add (& Head , -5);
	Baum_Add (& Head , 3);
	Baum_Add (& Head , 2);
	Baum_Add (& Head , 7);
	puts (" Elemente im Baum :");
	Baum_Print ( Head );
	puts (" ------------------------");
	DataMin = Baum_Min ( Head );
	DataMax = Baum_Max ( Head );
	printf (" Kleinste Wert im Baum : %d\n", DataMin );
	printf (" Groesste Wert im Baum : %d\n", DataMax );
	puts (" ------------------------");
	printf (" Gesuchte element : %d, Anzahl = %d\n", Gesucht , Baum_Find (Head , Gesucht ));
	printf (" Gesuchte element : %d, Anzahl = %d\n", DataMin , Baum_Find (Head , DataMin ));
	printf (" Gesuchte element : %d, Anzahl = %d\n", 9, Baum_Find (Head , 9));
	puts (" ------------------------");
	printf (" Durchschnitt der Messwerten : %lf\n", Baum_Avg ( Head ));
	puts (" ------------------------");
	puts (" Baum wird geloescht !");
	Baum_Delete (& Head );
	printf (" Wert von Zeiger Head : %p\n", (void*)Head );
	Baum_Print ( Head );
	return 0;
}



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


int Baum_Find ( Knote *Head , int Data )
{
    if(Head == NULL) return 0;
    if(Head->Data == Data) return Head->Anzahl;
    if(Head->Data > Data) return Baum_Find(Head->Right, Data);
    return Baum_Find(Head->Left, Data);
}

int normal_baum_avg(Knote * Head,  int* anzahl)
{
    if(Head == NULL)return 0;
    *anzahl+=Head->Anzahl;
    return normal_baum_avg(Head->Left, anzahl) + normal_baum_avg(Head->Right, anzahl)+(Head->Data)*Head->Anzahl;
}

double Baum_Avg(Knote *Head)
{
    int anzahl = 0;
    double sum = (double)normal_baum_avg(Head, &anzahl);
    return sum / (double)anzahl;
}