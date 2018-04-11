#include <iostream>
#include "String.h"

using namespace std;
using namespace TheUltimateString;

int main()
{
	// Erste Aufgabeteil
	String str1 = "Hello Moneypenny.";
	printf(str1);

	str1 = "My name is Bond. ";
	str1 += "James Bond.";
	
	printf("\n%s\n",(const char*) str1);

	if(str1 == (String)"My name is Bond. James Bond." 
				&&!(str1 != (String) "My name is Bond. James Bond." ))
	{
		cout << "Oh, Mr. Bond!" << endl;
	}

	// Zweite Aufgabeteil
	String strnum = "1234";
	if(strnum.isAllDigit())
	{
		cout << "This string is a number: ";
		int value = (int) strnum;
		cout << value  << endl;
	}
	else cout << "This string is not a number!";
	
	return 0;
}

