#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH
#include<iostream>
#include "Interfejs_Drona.hh"


class Przeszkoda {
protected:
  static int ile_utworzono;
  static int ile_istnieje;
public:

  
  
  virtual bool Czy_Kolizja(const Interfejs_Drona & Dr)=0;

  virtual void Dodaj_Przeszkode(){
    ile_utworzono++;    
    ile_istnieje++;
  }

  virtual void Usun_Przeszkode(){
    ile_istnieje--;
  }
  
  static int Zwroc_Istniejace(){
    return ile_istnieje;
  }

  static int Zwroc_Utworzone(){
    return ile_utworzono;
}


};



#endif

