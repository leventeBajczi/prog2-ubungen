#ifndef _MATRIX_HPP
#define _MATRIX_HPP

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
};

#endif