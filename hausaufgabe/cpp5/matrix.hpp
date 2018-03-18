#ifndef _MATRIX_HPP
#define _MATRIX_HPP

using namespace std;
#include <iostream>

class Matrix3{
    private:
        int elements[9];
    public:
        Matrix3();
        Matrix3(const Matrix3&);
        Matrix3(int *);
        Matrix3(int);
        
        void multiplizieren(const Matrix3&);
        void add(const Matrix3&);

        int det();
        int max();

        void print();

        void transp();

        Matrix3 operator*(Matrix3);
        Matrix3 operator+(Matrix3);
        friend Matrix3 operator+(int, Matrix3);
        Matrix3 operator+(int);
        Matrix3 operator+=(Matrix3);
        friend ostream& operator<<(ostream& , Matrix3);
        bool operator==(Matrix3);
        friend int& max(Matrix3&);

};



#endif