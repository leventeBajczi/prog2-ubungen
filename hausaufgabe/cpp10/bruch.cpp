#include <iostream>
using namespace std;

class Bruch
{
    private:
        int num, dnum;
    public:
        Bruch(int n, int d) : num(n), dnum(d) {}
        Bruch() : num(0), dnum(1) {}
        operator double()const{return ((double)num) / dnum;}
        operator int()const{return num / dnum;}
        friend ostream& operator<<(ostream&, Bruch&);
        bool operator<(Bruch& b)
        {
            return (double)*this < (double)b;
        }
};

ostream& operator<<(ostream& os, Bruch& b)
{
    os << b.num << "/" << b.dnum;
    return os;
}

template <typename T>
inline void printer(T* t, int n)
{
    for(int i = 0; i<n; i++)
        std::cout<<t[i]<<"\t";
}

template <typename T>
inline void sorter(T* t, int n)
{
    bool end = false;
    T tmp;
    while(!end)
    {
        end = true;
        for(int i = 0; i<n-1; i++)
            if(t[i] < t[i+1])
            {
                end = false;
                tmp = t[i+1];
                t[i+1] = t[i];
                t[i] = tmp;
            }
    }
}


int main()
{
	// Aufgabeteil I.
	Bruch B(9,4); 	// B = 9/4
	int ix = B; 	// ix solle 2 sein
	double dx = B;	// dx soll 2.25 sein
	cout << B << '\t' << ix << '\t' << dx << endl; // 9/4  2   2.25	
	
	// Aufgabeteil II.
	double darr[]  = {1.2, -4.5, 4.5, 5.7, 9.2};
	int iarr1[]    = {1, 0, -3, 4, 2, 5};
	int iarr2[]    = {1, 2, -3, 6, 9, 7};
	int isize = sizeof(iarr1)/sizeof(iarr1[0]);
	int dsize = sizeof(darr)/sizeof(darr[0]);
	
	Bruch *barr = new Bruch[isize];
	for (int i=0; i<isize; i++)
	{
		Bruch Btmp(iarr1[i],iarr2[i]);
		barr[i] = Btmp;
	}
	
	printer(darr, dsize);  // 1.2   -4.5    4.5 5.7     9.2
	cout << endl;
	sorter(darr, dsize);
	printer(darr, dsize);  // 9.2   5.7     4.5     1.2     -4.5
	cout << endl;

	printer(iarr1, isize);    //  1   0   -3  4   2   5
	cout << endl;
	sorter(iarr1, isize);
	printer(iarr1, isize);    //  5   4   2   1   0   -3 

	cout << endl;
	printer(barr, isize);   //  1/1  0/2  -3/-3  4/6  2/9  5/7
	cout << endl;
	sorter(barr, isize);
	printer(barr, isize);   // 1/1  -3/-3  5/7  4/6  2/9  0/2

return 0;
}