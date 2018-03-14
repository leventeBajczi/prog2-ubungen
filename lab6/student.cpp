#include "student.hpp"


int Student::InstanzCnt = 0;
enum Format Student::Typ = SHORT;
const double Student::GeldFur5 = 40000;

bool Student::isValidNeptun(const string c)
{
    if(c.length() != 6) return false;
    for(int i = 0; i<6; i++)
    {
        if(!((c[i] >= '0' && c[i] <= '9') || (c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))) return false;
    }
    return true;
}

bool Student::isValidNeptun()
{
    return Student::isValidNeptun(this->Neptun);
}

ostream & operator<<(ostream & os, Student & student)
{
    switch(student.Typ)
    {
        case(SHORT):
            os << student.Name << endl;
            break;
        case(FULL):
            os << "Student " << student.Name << ", " << student.Neptun << ", mit Durchschnitt " << student.Durchschnitt << " bekommt " << student.GeldFur5 << " HUF." << endl;
            break;
    }
    return os;
}
istream & operator>>(istream & is, Student ** student)
{
    char Name[40], Neptun[10];
    double Durchschnitt;
    cout << "Neuen Student einlesen:" << endl << "Name: ";
    is.getline(Name, 40);
    cout << "Neptun: ";
    is >> Neptun;
    cout << "Durchschnitt: ";
    is >> Durchschnitt;
    *student = new Student(Name, Neptun, Durchschnitt);
    return is;

}