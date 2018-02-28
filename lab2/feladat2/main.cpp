#include <cstdio>
#include <cstdlib>

#include <iostream>
using namespace std;

/* Általános megállapodások.
1. Ha a stack üres, a pData NULL, az elements 0.
2. Az pData mutat az elemek tömbjére, dinamikus memóriafoglalással.
3. Az elements jelzi az stackben lévo aktuális elemek számát.
4. A függvények karbantartják a dinamikus memóriaterületet
5. A stack használata elott a meg kell hívni a void stack_init(struct stack* s)-et.
6. A stack használata után meg kell hívni a void stack_cleanUp(struct stack* s)-t.
7. A függvények visszatérése hiba esetén nem nulla
*/

#include "stack.hpp"

int main(void)
{
	struct stack s;
	char c;
	char str[] = "Stacktest";
	
	cout << "Initializing stack...\n";
	stack_init(s);

	for(c = 'A' ; c <= 'Z' ; c++)
	{		
		cout << "push: " << c << '\n';
		// Itt nézzük a s.pData változót debuggerbol, lépjünk bele a függvénybe
		if (stack_push(s , c)) cout << "Stack ist full!\n";       
	}

	while(!stack_isEmpty(s))
	{
		// Itt nézzük a s.pData változót debuggerbol, lépjünk bele a függvénybe
		cout<<"pop: " << (char) stack_pop(s) << '\n';
	}
	
	if(stack_push(s, str)) printf("String zu lang, stack Full!\n");
	else cout << "String im Stack eingelegt!\n";

	while(!stack_isEmpty(s))
	{
		cout << "pop: " << (char) stack_pop(s) << '\n';
	}
	
	// Üres stackbol kivétel: hiba (-1)
	cout << "pop: " << (double) stack_pop(s) << '\n';
	
	cout << "Cleaning up stack...\n";
	stack_cleanUp(s);
	
return 0;
}