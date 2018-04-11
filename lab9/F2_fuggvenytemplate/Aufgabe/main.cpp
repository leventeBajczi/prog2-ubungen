#include <iostream>
#include <string>
using namespace std; 
 
class cplx
{
	private:
		double re, im;
	public:
		cplx(double re=0, double im=0): re(re), im(im) {}
		~cplx () {}
		friend ostream& operator<<(ostream&, cplx&); 
		bool operator<(cplx& c)
		{
			return (re*re+im*im) < (c.re*c.re+c.im*c.im);
		}
};


ostream& operator<<(ostream& os, cplx& c)
{
	os<<c.re<<"+"<<c.im<<"i";
	return os;
}
 

template <typename T>
inline T& findmax(T* t, int n)
{
	T& tmp = t[0];
	for(int i = 1; i<n; i++)
		if(tmp < t[i]) tmp = t[i];
	return tmp;
}
 
int main()
{
	int iarr[] 		= {1, -3, 5, 7, 6};
	double darr[] 	= {6.2, 3.4, 5.6, -1.5, 0.6};
	cplx carr[5];
	
	for (int i=0; i<5; i++)
	{
		cplx tmp(darr[i], (double) iarr[i]);
		carr[i] = tmp;
	}
	
	for(int i=0; i<5; i++) cout << darr[i] << '\t';
	cout << endl;
	for(int i=0; i<5; i++) cout << iarr[i] << '\t';
	cout << endl;
	for(int i=0; i<5; i++) cout << carr[i] << '\t';
	cout << endl;

	cout << findmax<int>(iarr,5)    << endl;
	cout << findmax<double>(darr,5) << endl;
	cout << findmax<cplx>(carr,5)   << endl;	// Absolutwert soll verglichen werden
	
	return 0;
}