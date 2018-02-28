#include <stdio.h>
#include "baum.h"

int main()
{
Knote *Head = NULL;
int DataMin, DataMax;

    Baum_Print(Head);
	puts("------------------------");
	puts("Baum wird Aufgebaut!");

	Baum_Add(&Head, 2);
	Baum_Add(&Head, -5);
	Baum_Add(&Head, 3);
	Baum_Add(&Head, 2);
	Baum_Add(&Head, 7);

	puts("Elemente im Baum:");
	Baum_Print(Head);
	puts("------------------------");

	DataMin = Baum_Min(Head);
	DataMax = Baum_Max(Head);

	printf("Kleinste Wert im Baum: %d\n", DataMin);
	printf("Grosste Wert im Baum: %d\n", DataMax);

    puts("------------------------");
    puts("Baum wird geloescht!");
    Baum_Delete(&Head);
    printf("Wert von Zeiger Head: %p\n", Head);
    Baum_Print(Head);

return 0;
}