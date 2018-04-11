#ifndef STRING_H
#define STRING_H
#include <iostream>

namespace TheUltimateString
{
	class String
	{
		// A karakterek aktuális száma:
		unsigned int elementsNum;

		// A karaktereket tartalmazó memóriaterületre mutató pointer:
		char*pData;
	public:
		// Argumentum nélküli konstruktor:
		String();

		// Egy NULL végu sztringet váró konverziós konstruktor
		// Ez felel a char*-> String konverzióért
		String(const char* str);

		// A destruktor:
		~String(){delete[]pData;}
		
		// Visszatér a sztring hosszával
		unsigned int getLength()const{return elementsNum;}

		// Összefuz két Stringet
		const String& operator+=(const String &theOther);
		const String& operator=(const String& theOther);
		bool operator==(const String& theOther)const;
		bool operator!=(const String& theOther)const{return !(*this==theOther);};

		// Visszaad egy  csak olvasható hozzáférést a stringhez
		operator const char*()const;
		operator int();
		
		bool isAllDigit(void);		
	};
}
#endif /* STRING_H */