#include "dreieck.hpp"
#include <cmath>

double Dreieck::EPS = 1e-5;

Dreieck::Dreieck(double ii, double ij, double ik, typus type)
{
    switch(type)
    {
        case ZWEI_SEITEN_EINE_WINKEL:               //Negative seite -> absolutwert, >=pi winkel (und absolutwert) -> pi/3
            set_a(std::abs(ii));
            set_b(std::abs(ij));
            ik = std::abs(ik);
            if(ik < M_PI)set_c(seite(a, b, ik));
            else set_c(seite(a, b, M_PI/3));
            
            break;
        case ZWEI_WINKELN_EINE_SEITE:               //Negative seite -> absolutwert, >=pi winkel (und absolutwert) -> pi/3
            set_a(std::abs(ii));
            ij = std::abs(ij);
            ik = std::abs(ik);
            if(ij + ik < M_PI)
            {
                set_b(seite(a, M_PI - ij - ik, ij, true));  //'true' ist nur fuer die Moeglichkeit fuer overloading (anderes Method, aber anderns waere die gleiche parameterlist)
                set_c(seite(a, M_PI - ij - ik, ik, true));
            }
            else
            {
                set_b(seite(a, c, M_PI/3));
                set_c(seite(a, b, M_PI/3));
            }
            
            break;
        case DREI_SEITEN:                           //Negative Seiten -> absolutwert, falls dreiecksungleichung nicht wahr ist, wird eine Dreieck mit PI/3 Winkeln und 1cm Sieten instanziiert
            ii = std::abs(ii);
            ij = std::abs(ij);
            ik = std::abs(ik);

            if( (ii + ij > ik) && (ij + ij > ii) && (ik + ij > ij))
            {
                set_a(ii);
                set_b(ij);
                set_c(ik);
            }
            else{
                set_a(1);
                set_b(1);
                set_c(1);
            }
            break;
            
    }
}


void Dreieck::print()
{
    std::cout<<"Seiten (cm):  "<<a<<"\t"<<b<<"\t"<<c<<std::endl;
}


double Dreieck::oberflaeche()
{
    return a*b*std::sin(get_gamma())/2.0;
}
double Dreieck::umfang()
{
    return a+b+c;
}
bool Dreieck::rechtwinklig()
{
    return ( std::abs(get_alpha() - M_PI/2) < EPS || std::abs(get_beta() - M_PI/2) < EPS || std::abs(get_gamma() - M_PI/2) < EPS);
}

double Dreieck::umkreis_radius()
{
    return a / 2.0 / std::sin(get_alpha());
}
double Dreieck::inkreis_radius()
{
    return a / (1.0 / std::tan(get_beta()/2) + 1.0 / std::tan(get_gamma()/2));
}



double Dreieck::get_a()
{
    return a;
}
double Dreieck::get_b()
{
    return b;
}
double Dreieck::get_c()
{
    return c;
}

double Dreieck::get_alpha()
{
    return winkel(b, c, a);
}
double Dreieck::get_beta()
{
    return winkel(a, c, b);
}
double Dreieck::get_gamma()
{
    return winkel(a, b, c);
}

void Dreieck::set_a(double a)
{
    this->a = a;
}
void Dreieck::set_b(double b)
{
    this->b = b;
}
void Dreieck::set_c(double c)
{
    this->c = c;
}

double Dreieck::winkel(double a, double b)
{
    return 2*M_PI - a - b;
}

double Dreieck::winkel(double a, double b, double c)
{
    return std::acos((c*c - a*a - b*b) / (-2 * a * b));
}

double Dreieck::seite(double a, double b, double c)
{
    return std::sqrt(a*a + b*b - 2*a*b*std::cos(c));
}

double Dreieck::seite(double a, double alpha, double beta, bool override_flag)
{
    return a / std::sin(alpha) * std::sin(beta);
}