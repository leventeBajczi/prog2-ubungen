#include <stdio.h>
#include <stdlib.h>

/* Általános megállapodások.
1. Ha a stack üres, a pData NULL, az elements 0.
2. Az pData mutat az elemek tömbjére, dinamikus memóriafoglalással.
3. Az elements jelzi az stackben lévo aktuális elemek számát.
4. A függvények karbantartják a dinamikus memóriaterületet
5. A stack használata elott a meg kell hívni a void stack_init(struct stack* s)-et.
6. A stack használata után meg kell hívni a void stack_cleanUp(struct stack* s)-t.
7. A függvények visszatérése hiba esetén nem nulla
*/

#include "stack.h"

int main(void)
{
	struct stack s;
	char c;
	char str[]="Stacktest";
	
	printf("Initializing stack...\n");
	stack_init(&s);

	for(c = 'A' ; c <= 'Z' ; c++)
	{		
		printf("push: %c\n" , c);
		// Itt nézzük a s.pData változót debuggerbol, lépjünk bele a függvénybe
		if (stack_push(&s , c)) printf("Stack Full!\n");       
	}

	while(!stack_isEmpty(&s))
	{
		// Itt nézzük a s.pData változót debuggerbol, lépjünk bele a függvénybe
		printf("pop: %c\n", (char) stack_pop(&s));
	}
	
	if(stack_pushstring(&s, str)) printf("String zu lang, stack Full!\n");
	else printf("String im Stack eingelegt!\n");

	while(!stack_isEmpty(&s))
	{
		printf("pop: %c\n", (char) stack_pop(&s));
	}
	
	// Üres stackbol kivétel: hiba (-1)
	printf("pop: %d\n",stack_pop(&s));
	
	printf("Cleaning up stack...\n");
	stack_cleanUp(&s);
	
return 0;
}

