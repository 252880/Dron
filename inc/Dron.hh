#ifndef DRON_HH
#define DRON_HH

#include<unistd.h>
#include<iostream>
#include "Prostopadloscian.hh"
#include "Sruba.hh"
#include "Interfejs_Drona.hh"
#include "Przeszkoda.hh"
#include "Przeszkoda_Prost.hh"

class Dron : public Prostopadloscian,public Interfejs_Drona{
protected:

  Sruba s1,s2;
  
  std::shared_ptr<Przeszkoda> P;
  std::shared_ptr<Dron> D;
public:

  Dron();
  Dron(drawNS::APIGnuPlot3D *obiekt, Wektor<double,3>*x,Wektor<double,3>*y,Wektor<double,3> sr,MacierzO &obr,uint &id,MacierzO &o)
    :Prostopadloscian(obiekt,x,sr,obr,id),s1(obiekt,y,sr,obr,id,o),s2(obiekt,y,sr,obr,id,o){};
														      


    

void  ruch_animowany(double kat, double odleglosc){
      
    Wektor<double,3> X;
    double rad= (3.14*kat)/180;
    

    X[0]=odleglosc*cos(rad);
    X[1]=0;
    X[2]= odleglosc*sin(rad);

    for(int i=0;i<100;i++){
      sr=sr+(obr*(X/100));


      usun();
      rysuj();

 usleep(19900);
           

    }
  }
  
  void rotacja(double kat){
    for(int i=0;i<100;i++){       	         

        s1.rotacja(kat/100);
	s2.rotacja(kat/100);
        Prostopadloscian::rotacja(kat/100);

     
	usun();      
	rysuj();

	 usleep(19900);
     
	
    }    
  };

  
  void rysuj(){
    
    s2.rysuj(obr*Dron::wierzch[3]+sr);      //srodek jest krawedzia drona
    s1.rysuj(obr*Dron::wierzch[0]+sr);
    Prostopadloscian::rysuj();
  };



  bool czy_kolizja(const Interfejs_Drona &  Dr){
  }
 
  

  MacierzO get_Macierz_Obrotu(){
    return obr;
}
 

  void usun(){
    
    s1.usun();
    s2.usun();
 
      s1.obrot();
      s2.obrot();
      
  }
};  
 
#endif                                                       
 
