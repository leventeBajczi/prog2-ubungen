#ifndef STRING_H
#define STRING_H
#include <iostream>

namespace TheUltimateString
{
	class String
	{
		// A karakterek aktu�lis sz�ma:
		unsigned int elementsNum;

		// A karaktereket tartalmaz� mem�riater�letre mutat� pointer:
		char*pData;
	public:
		// Argumentum n�lk�li konstruktor:
		String();

		// Egy NULL v�gu sztringet v�r� konverzi�s konstruktor
		// Ez felel a char*-> String konverzi��rt
		String(const char* str);

		// A destruktor:
		~String(){delete[]pData;}
		
		// Visszat�r a sztring hossz�val
		unsigned int getLength()const{return elementsNum;}

		// �sszefuz k�t Stringet
		const String& operator+=(const String &theOther);
		const String& operator=(const String& theOther);
		bool operator==(const String& theOther)const;
		bool operator!=(const String& theOther)const{return !(*this==theOther);};

		// Visszaad egy  csak olvashat� hozz�f�r�st a stringhez
		operator const char*()const;
		operator int();
		
		bool isAllDigit(void);		
	};
}
#endif /* STRING_H */