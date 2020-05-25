#ifndef FIGURA3D_HH
#define FIGURA3D_HH

#include "Rysuj_Obiekt.hh"
#include <cmath>

class Figura3D : public Rysuj_Obiekt { 
protected:
  Wektor<double,3> sr;      //srodek figury
  MacierzO obr;             //macierz obrotu
  uint id;                  // id obiektu


public:

  Figura3D(drawNS::APIGnuPlot3D *obiekt, Wektor<double,3> & x, MacierzO & y,uint &z): Rysuj_Obiekt(obiekt), sr(x), obr(y){};
 ~Figura3D(){};  
  void rysuj()=0;
};


 
#endif
