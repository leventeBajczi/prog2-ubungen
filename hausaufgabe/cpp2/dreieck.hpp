#ifndef _DREICK_HPP
#define _DREICK_HPP

#include <iostream>

enum typus{
        ZWEI_SEITEN_EINE_WINKEL,
        ZWEI_WINKELN_EINE_SEITE,
        DREI_SEITEN
};


class Dreieck{
    
    private:
        double a, b, c;
        static double EPS;

        void set_a(double);
        void set_b(double);
        void set_c(double);

        double winkel(double, double, double);
        double winkel(double, double);
        double seite(double, double, double);
        double seite(double, double, double, bool);
    public:
        Dreieck(double, double, double, typus);
        double oberflaeche();
        double umfang();
        bool rechtwinklig();

        double umkreis_radius();
        double inkreis_radius();

        void print();

        double get_a();
        double get_b();
        double get_c();

        double get_alpha();
        double get_beta();
        double get_gamma();

};

#endif