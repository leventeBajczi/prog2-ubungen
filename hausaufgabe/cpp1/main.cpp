#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct P{
    double x;
    double y;
};

int GetMax(int a[], int n)
{
    int max;
    for(int i = 0; i<n; i++){
        if(a[i] > max) max=a[i];
    }
    return max;
}

double GetMax(double a[], int n)
{
    double max;
    for(int i = 0; i<n; i++){
        if(a[i] > max) max=a[i];
    }
    return max;
}

char GetMax(char str[])
{
    char max;
    for(unsigned int i = 0; i<strlen(str); i++){
        if(str[i] > max) max=str[i];
    }
    return max;
}

double laenge2(P p)
{
    return p.x*p.x + p.y*p.y;
}

char* GetMax(P a[], int n)
{
    P max;
    for(int i = 0; i<n; i++){
        if(laenge2(a[i]) > laenge2(max)) max=a[i];
    }
    char *str = new char[8];
    sprintf(str, "%2.1f, %2.1f", max.x, max.y);
    return str;
}


int main(){

    int v[7] = {1, 2, 5, 3, 9, 4 , 6};
    double v2[7] = {1.0, 2.0, 5.6, 3.3, 9.8, 4.5 , 6.6};
    char str[] = "Schumacher";
    char *poi = NULL;
    struct P Points[3] = {{1.0,1.0},{3.4,5.5},{-1,0.1}};

    cout << "Groesste Element in v:" << GetMax(v, 7) << endl; 
    // soll 9 liefern

    cout << "Groesste Element in v2:" << GetMax(v2, 7) << endl; 
    // soll 9.8 liefern

    cout << "Groesste Element in str:" << GetMax(str) << endl;
    // soll 'u' liefern als "groesste" Buchstabe

    cout << "Groesste Element in Points:";
    poi = GetMax(Points, 3);
    cout << poi << endl;
    // soll "3.4, 5.5" als string liefern (mit new)
    // Punkt mit groesstem Abstand von dem Origo (0,0).
    // Eine Stelle nach dem Komma ist ausreichend!
    delete [] poi;
    return 0;
}

