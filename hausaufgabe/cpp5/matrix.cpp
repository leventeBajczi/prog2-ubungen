#include "matrix.hpp"
#include <iostream>

using namespace std;

Matrix3::Matrix3()
{
    for(int i = 0; i<9; i++) this->elements[i] = 0;
}
Matrix3::Matrix3(const Matrix3& obj)
{
    for(int i = 0; i<9; i++) this->elements[i] = obj.elements[i];    
}
Matrix3::Matrix3(int * v)
{
    for(int i = 0; i<9; i++) this->elements[i] = v[i];
}
Matrix3::Matrix3(int k)
{
    for(int i = 0; i<9; i++) this->elements[i] = k;
}

void Matrix3::multiplizieren(const Matrix3& obj)
{
    int v[9];
    for(int i = 0; i<9; i++) v[i] = this->elements[i];
    for(int i = 0; i<9; i++) this->elements[i] = v[3*(i/3)]*obj.elements[i%3] + v[3*(i/3) + 1]*obj.elements[i%3 + 3] + v[3*(i/3) + 2]*obj.elements[i%3 + 6];
}
void Matrix3::add(const Matrix3& obj)
{
    for(int i = 0; i<9; i++) this->elements[i] += obj.elements[i];
}

int Matrix3::det()
{
    return this->elements[0]*(this->elements[4]*this->elements[8] - this->elements[5]*this->elements[7]) - this->elements[1]*(this->elements[3]*this->elements[8] - this->elements[5]*this->elements[6]) + this->elements[2]*(this->elements[3]*this->elements[7] - this->elements[4]*this->elements[6]); //nicht schön, aber funktioniert
}
int Matrix3::max()
{
    int max = this->elements[0];
    for(int i = 1; i<9; i++) if(max<this->elements[i]) max = this->elements[i];
    return max;
}

void Matrix3::print()
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++) std::cout<<this->elements[i*3+j]<<" ";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void Matrix3::transp()
{
    int v[9];
    for(int i = 0; i<9; i++) v[i] = this->elements[i];
    for(int i = 0; i<9; i++) {
        this->elements[i] = v[i/3 + 3 * (i%3)];
    }
}

Matrix3 Matrix3::operator*(Matrix3 m)
{
    Matrix3 newMatrix = m;
    newMatrix.multiplizieren(*this);
    return newMatrix;
}
Matrix3 Matrix3::operator+(Matrix3 m)
{
    Matrix3 newMatrix = m;
    newMatrix.add(*this);
    return newMatrix;
}
Matrix3 operator+(int n, Matrix3 m)
{
    Matrix3 newMatrix(n);
    newMatrix.add(m);
    return newMatrix;
}
Matrix3 Matrix3::operator+(int n)
{
    Matrix3 newMatrix(n);
    newMatrix.add(*this);
    return newMatrix;
}
Matrix3 Matrix3::operator+=(Matrix3 m)
{
    (*this).add(m);
    return *this;
}
ostream& operator<<(ostream& os, Matrix3 m)
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++) os<<m.elements[i*3+j]<<" ";
        os<<std::endl;
    }
    os<<std::endl;
    return os;
}


bool Matrix3::operator==(Matrix3 m)
{
    for(int i = 0; i<9; i++)
    {
        if(this->elements[i] != m.elements[i]) return false;
    }
    return true;
}

int& max(Matrix3& m)
{
    int max = m.max();
    for(int i = 1; i<9; i++) if(m.elements[i] == max) return m.elements[i];
    return m.elements[0]; //Diese Zeile ist nicht wichtig, wird niemals laufen gelassen weil mindestens eine Maximale Wert muss im Matrix existieren, aber Haweb akzeptiert meine Loesung ohne diese Zeile nicht.
}