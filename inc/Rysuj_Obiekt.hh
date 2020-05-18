#ifndef OBIEKT_HH
#define OBIEKT_HH
#include "Dr3D_gnuplot_api.hh"
#include"Wektor.hh"
#include"Macierz.hh"
#include"MacierzO.hh"

class Rysuj_Obiekt {
protected:
  std::shared_ptr<drawNS::Draw3DAPI> api;
public:
  Rysuj_Obiekt(drawNS::Draw3DAPI  *obiekt): api(obiekt){}
  virtual void rysuj() = 0;
  virtual ~Rysuj_Obiekt(){}
};
#endif
