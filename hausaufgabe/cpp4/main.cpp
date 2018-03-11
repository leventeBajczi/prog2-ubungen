#include <iostream>
#include "matrix.hpp"
using namespace std;

int main()
{
    int v[9] ={1,2,3,4,5,6,7,8,9};

    Matrix3 a1; // Alle Elemente 0 sind.
    Matrix3 a2(a1); // a2 initializiert durch a1
    Matrix3 a3(v); // a3 durch vector initializiert: d.h. a3[i][j]=v[3i+j];
    Matrix3 a4(4); // Alle Elemente 4 sind.

    a3.multiplizieren(a4); // a3 = a3 * a4 (nicht elementaerweise!)
    a2.add(a4); // a2 = a2 + a4

    cout << a3.det() << endl; // Soll die Determinante ausgeben
    cout << a3.max() << endl; // Groesste Element ausgeben

    a1.print();
    // Matrix soll auf dem Bildschirm ausgegeben werden:
    // 0  0  0
    // 0  0  0	
    // 0  0  0

    a2.print();

    a3.print();

    a3.transp(); // a3 wird trasponiert

    a3.print();

    a4.print();

    return 0;
}