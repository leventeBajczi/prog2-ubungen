#include "String.h"

#include <cstring>

using namespace TheUltimateString;
String::String()
{
    pData=NULL;
    elementsNum = 0;
}

String::String(const char* str)
{
    elementsNum = strlen(str);
    pData = new char[elementsNum+1];
    strcpy(pData, str);
}

const String& String::operator+=(const String &theOther)
{
    char* tmp = new char[elementsNum + theOther.getLength() + 1];
    strcpy(tmp, pData);
    strcpy(tmp+elementsNum, theOther.pData);
    elementsNum += theOther.elementsNum;
    delete [] pData;
    pData = tmp;
    return (const String&)*this;
}
const String& String::operator=(const String& theOther)
{
    char* tmp = new char[theOther.getLength() + 1];
    strcpy(tmp, theOther.pData);
    elementsNum = theOther.elementsNum;
    delete [] pData;
    pData = tmp;
    return (const String&)*this;
}
bool String::operator==(const String& theOther)const
{
    if(this == &theOther) return true;
    if(elementsNum != theOther.elementsNum) return false;
    for(int i = 0; i<elementsNum; i++)
    {
        if(pData[i] != theOther.pData[i]) return false;
    }
    return true;
}

String::operator const char*()const
{
    return (const char*)pData;
}
String::operator int()
{
    int c = 0;
    for(int i = 0; i<elementsNum; i++)
        c=c*10+pData[i]-'0';
    return c;
}

bool String::isAllDigit()
{
    for(int i = 0; i<elementsNum; i++)
        if(pData[i] > '9' || pData[i] < '0') return false;
    return true;
}		