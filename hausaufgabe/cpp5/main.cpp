#include <iostream>
#include "matrix.hpp"

using namespace std;

int main()
{
    int v[9] = {1,2,3,4,5,6,7,8,9};

    Matrix3 a1;     // Alle Elemente 0 sind.
    Matrix3 a2(a1); // a2 initializiert durch a1
    Matrix3 a3(v);  // a3 durch vector initializiert: d.h. a3[i][j] = v[3i+j];
    Matrix3 a4(4);  // Alle Elemente 4 sind.

    a1 = a1 * a4; // a1 wird durch a4 multipliziert und
                // ins a1 gespeichert.

    a1 = a1 + 3;    // a1 = a1 + 3, 3 wird zum jedem Element addiert.
    a2 = 3 + a2;    // a2 = 3 + a2, 3 wird zum jedem Element addiert.
    a4 = a1 + a2;   // a4 = a1 + a2, a4 wird gleich mit a1+a2.
    a1 += a2;       // a1 = a1 + a2.

    max(a3) = 11;    // Groesste Element im a3 wird durch 11 ersetzt.
    cout << max(a3); // Groesste Element wird ausgeschrieben.

    if (a4 == a1) {cout << "Identisch!\n";}

    //a1.print();
    //a2.print();
    //a3.print();
    //a4.print();
    cout << a1; // sollte 6,6,6;6,6,6;6,6,6 ausschreiben
    cout << a2; // sollte 3,3,3;3,3,3;3,3,3 ausschreiben
    cout << a3; // sollte 1,2,3,4,5,6,7,8,11 ausschreiben
    cout << a4; // sollte 6,6,6;6,6,6;6,6,6 ausschreiben

    return 0;
}
