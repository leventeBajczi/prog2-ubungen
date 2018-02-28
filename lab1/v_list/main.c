#include <stdio.h>
#include "list.h"

int main()
{
    ListElem *Head = NULL;
     
    TelefonBuch_Print(Head);
    
    puts("------------------------------------");    
    Head = TelefonBuch_Add(Head, "Sujbert Laszlo", 4633213);
    Head = TelefonBuch_Add(Head, "Nagy Lajos", 4632225);
    Head = TelefonBuch_Add(Head, "Horvath Peter", 2568275);
    Head = TelefonBuch_Add(Head, "Vajta Laszlo", 1223213);
    
    puts("Inhalt des Telefonbuches:");    
    TelefonBuch_Print(Head);
    
    puts("------------------------------------");   
    Head = TelefonBuch_Delete(Head);
    puts("Liste geloescht!");
	
	puts("------------------------------------");   
	puts("Inhalt des Telefonbuches:");    
    TelefonBuch_Print(Head);

return 0;
}