#include <iostream>

using namespace std;

int pow(int a, int b) // In der Beispiel nur positive ganze Zahlen sind benutzt
{
    int n = a;
    for(int i = 1; i<b; i++)a*=n;
    return a;
}

class Bruch {
    private:
        int num, dnum; // Bruch representiert: num / dnum
    public:
        Bruch(){num = 0; dnum = 1;}
        Bruch(int n, int d){num = n; dnum = d;}
        Bruch(const Bruch& obj){this->num = obj.num; this->dnum=obj.dnum;}
        friend ostream& operator<<(ostream& os, Bruch& b){os << b.num << "/" <<b.dnum; return os;}
        Bruch operator^(int n){Bruch b(pow(num, n), pow(dnum, n)); return b;}
        Bruch operator++(int n)
        {
            Bruch b = *this;
            this->num+=this->dnum;
            return b;
        }
};


int main(void)
{
    Bruch B1(3,2), B11; // (*) B1 = 3/2, B11 = 0/1
    Bruch B2(B1);       // (*) B2 = 3/2

    cout << B1 << endl << B11 << endl << B2; // (**)
    // Soll 3/2, 0/1 und 3/2 auf dem Bildschirm schreiben

    B11 = B2 = B1; // (***)   B11 = B2 = 3/2
    B1 = B2 ^ 3;   // (****)  B1 = 27/8
    B2 = B1++;     // (*****) B1 = 35/8 und B2 = 27/8

    cout << B2 << endl << B1;    // Soll 27/8 und 35/8 auf dem Bildschirm erscheinen

    return 0;
}