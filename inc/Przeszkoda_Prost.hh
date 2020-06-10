#ifndef PRZESZKODA_PROST_HH
#define PRZESZKODA_PROST_HH


#include "Przeszkoda.hh"
#include "Prostopadloscian.hh"

#include<cmath>

class Przeszkoda_Prost :  public Prostopadloscian,public Przeszkoda{
 
public:
  Przeszkoda_Prost();
  Przeszkoda_Prost(drawNS::APIGnuPlot3D *obiekt, Wektor<double,3>*x,std::string k,Wektor<double,3> sr, MacierzO &obr,uint &id)
    :Prostopadloscian(obiekt,x,k,sr,obr,id){};
  

  
 

  bool Czy_Kolizja(const Interfejs_Drona & Dr){

    Wektor<double,3> s=(wierzch[0]+wierzch[6])*0.5;
    Wektor<double,3> a=s-wierzch[0];
    Wektor<double,3> b=Dr.get_srodek()-Dr.get_wierzch();
    Wektor<double,3> c =Dr.get_srodek()-s;
    double d=0,e=0,f=0;

    for(int x=0;x<3;x++){
      c[x]=c[x]*c[x];
      a[x]=a[x]*a[x];
      b[x]=b[x]*b[x];
    }

    for(int x=0;x<3;x++){
    d=a[x]+d;
    e=b[x]+e;
    f=c[x]+f;
    }
    d=sqrt(d);
    e=sqrt(e);
    f=sqrt(f);
    
    if((d+e)>f){
      std::cerr<<"Kolizja\n";
      return false;
	}
    return true;
  };

  void Dodaj_Przeszkode(){
    Przeszkoda::Dodaj_Przeszkode();
  

    Prostopadloscian::rysuj();
  }

  

  void Usun_Przeszkode(){
    api->erase_shape(id);
    Przeszkoda::Usun_Przeszkode();    
  }
};

#endif
