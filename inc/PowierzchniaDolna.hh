#ifndef POWIERZCHNIADOLNA_HH
#define POWIERZCHNIADOLNA_HH

#include "Rysuj_Obiekt.hh"
#include "Wektor.hh"
#include "Interfejs_Drona.hh"






class PowierzchniaDolna : public Rysuj_Obiekt{
public:
  PowierzchniaDolna();

  PowierzchniaDolna(drawNS::APIGnuPlot3D *obiekt) :Rysuj_Obiekt(obiekt){};




  void rysuj(){
    api->draw_surface(std::vector<std::vector<drawNS::Point3D>>
       {{ drawNS::Point3D(99,99,-99), drawNS::Point3D(99,-0,-99),drawNS::Point3D(99,-99,-99)
       },{
	  drawNS::Point3D(49,99,-99),drawNS::Point3D(49,-0,-99), drawNS::Point3D(49,-99,-99)
       },{
	  drawNS::Point3D(0,99,-99), drawNS::Point3D(0,-0,-99),drawNS::Point3D(0,-99,-99)
       },{
	  drawNS::Point3D(-49,99,-99),drawNS::Point3D(-49,-0,-99), drawNS::Point3D(-49,-99,-99)
       },{
	  drawNS::Point3D(-99,99,-99), drawNS::Point3D(-99,-0,-99),drawNS::Point3D(-99,-99,-99)}},"yellow");


 
  };


  
bool Czy_Kolizja(const Interfejs_Drona & Dr){

    Wektor<double,3> c =Dr.get_srodek();


    double d=0,e=0;
    e=c[2];
    d=-91;
    if(e<d){
      std::cerr<<"Kolizja\n";
      return false;
    }
    return true;
}
};

 
#endif
