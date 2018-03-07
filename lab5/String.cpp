#include "String.h"
#include <cstring>
String::String()
{
    this->pData = new char[1];
    this->pData[0] = 0;
    this->elementsNum = 0;
}

String::String(const String& obj)
{
    this->elementsNum = obj.elementsNum;
    this->pData = new char[this->elementsNum];
    strcpy(this->pData, obj.pData);
}

String::String(const char* str)
{
    this->elementsNum = strlen(str);
    this->pData = new char[this->elementsNum + 1];
    strcpy(this->pData, str);
}

String::String(const char c, unsigned int times)
{
    this->elementsNum = times;
    this->pData = new char[this->elementsNum + 1];
    for(int i = 0; i<times; i++)
    {
        this->pData[i] = c;
    }
    this->pData[times] = 0;
}

const String& String::operator=(const String& obj)
{
    if(this == &obj) return *this;
    delete [] this->pData;
    this->elementsNum = obj.elementsNum;
    this->pData = new char[this->elementsNum + 1];
    strcpy(this->pData, obj.pData);
    return *this;
}

bool String::operator==(const String& obj)
{
    if(this->elementsNum != obj.elementsNum) return false;
    for(int i = 0; i<obj.elementsNum; i++)
    {
        if(this->pData[i] != obj.pData[i]) return false;
    }
    return true;
}

bool String::operator!=(const String& obj)
{
    return !((*this)==obj);
}

String String::operator+(String& obj)
{
    String s;
    s.pData = new char[this->elementsNum + obj.elementsNum + 1];
    strcpy(s.pData, this->pData);

    strcpy(s.pData+this->elementsNum, obj.pData);
    s.elementsNum = this->elementsNum + obj.elementsNum;
    return s;
}

String String::operator+(char c)
{
    String s;
    s.pData = new char[this->elementsNum + 2];
    strcpy(s.pData, this->pData);

    s.pData[this->elementsNum] = c;
    s.pData[this->elementsNum + 1] = 0;
    s.elementsNum = this->elementsNum + 1;
    return s;
}

char String::operator[](int i)
{
    return (i< this->elementsNum && i>=0) ? this->pData[i] : 0;
}

void String::getStr(char* pBuff)
{
    strcpy(pBuff, this->pData);
}

unsigned  int String::getLength()
{
    return this->elementsNum;
}

ostream & operator<<(ostream & os, String & S)
{
    os<<S.pData;
    return os;
}

String operator+(const char c, String S)
{
    String s;
    s.pData = new char[S.elementsNum + 2];
    s.pData[0] = c;
    strcpy(s.pData+1, S.pData);

    s.elementsNum = S.elementsNum + 1;
    return s;   
}
