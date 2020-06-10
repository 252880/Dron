#ifndef SRUBA_HH
#define SRUBA_HH

#include "Graniastoslup6.hh"

class Sruba : public Graniastoslup6  {
protected:
  MacierzO o;      

public:

  Sruba();
  Sruba(drawNS::APIGnuPlot3D *obiekt, Wektor<double,3> *x, Wektor<double,3> &sr, MacierzO & obr,uint & id,MacierzO &os) : Graniastoslup6(obiekt,x,sr,obr,id), o(os) 
  {
    for(int i=0;i<12;i++)
      wierzch[i]=x[i];
  }

  void  rysuj(Wektor<double,3> x){
       
    sr=x;
    obr=obr*o;
    
   Graniastoslup6::rysuj();
    };

  void rotacja(double kat){

    MacierzO HLP(obr);
    obr.obrotZ(kat);
    obr=obr*HLP;
  
  };



  void obrot(){
  
  MacierzO HLP(o);
  o.obrotX(9);
  o=o*HLP;
}

  void usun(){
    api->erase_shape(id);
  }
  
};

#endif



