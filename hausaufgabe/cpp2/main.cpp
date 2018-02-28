#include "dreieck.hpp"
#include <cmath>
int main()
{
    Dreieck d1(3, 2, M_PI/4, ZWEI_SEITEN_EINE_WINKEL), d2(3, M_PI/3, M_PI/6, ZWEI_WINKELN_EINE_SEITE), d3(3, 4, 5, DREI_SEITEN);
    d1.print();
    d2.print();
    d3.print();
    std::cout<<"d1 Oberflaeche: "<<d1.oberflaeche()<<" cm*cm\tUmfang: " << d1.umfang() << " cm\t" <<(d1.rechtwinklig() ? "" : "nicht ") << "rechtwinklig" <<  std::endl;
    std::cout<<"d2 Daten: \t" << d2.get_a() << " cm\t" << d2.get_b() << " cm\t" << d2.get_c() << " cm\t\n\t" << d2.get_alpha() << " (rad)\t" << d2.get_beta() << " (rad)\t" << d2.get_gamma() << " (rad)" <<std::endl;
    std::cout<<"d3 Umkreis: r=" << d3.umkreis_radius() << " cm\tInkreis: R=" << d3.inkreis_radius() << " cm" << std::endl;
    return 0;
}