#ifndef PRZESZKODA_PROST_HH
#define PRZESZKODA_PROST_HH


#include "Przeszkoda.hh"
#include "Prostopadloscian.hh"


class Przeszkoda_Prost :  public Prostopadloscian,public Przeszkoda{
 
public:
  Przeszkoda_Prost();
  Przeszkoda_Prost(drawNS::APIGnuPlot3D *obiekt, Wektor<double,3>*x,Wektor<double,3> sr, MacierzO &obr,uint &id)
    :Prostopadloscian(obiekt,x,sr,obr,id){};
  

  
 

  bool Czy_Kolizja(const Interfejs_Drona & Dr){
    

  }

  void Dodaj_Przeszkode(Wektor<double,3> X){
    Przeszkoda::Dodaj_Przeszkode();
    sr=X;

    Prostopadloscian::rysuj();
  }

 


  

  void Usun_Przeszkode(){
    api->erase_shape(id);
  }
};

#endif
