#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include<string>
#include "Figura3D.hh"

class Prostopadloscian : public Figura3D {
protected:

  Wektor<double,3> wierzch[8];
  std::string kolor;

public:

  Prostopadloscian();
  Prostopadloscian(drawNS::APIGnuPlot3D *obiekt, Wektor<double,3> *x,std::string k ,Wektor<double,3> &sr, MacierzO & obr,uint & id) : Figura3D(obiekt,sr,obr,id),kolor(k)
  {
    for(int i=0;i<8;i++)
      wierzch[i]=x[i];
  }



  void  rysuj(){
         Prostopadloscian HLP(*this);
  for(int i=0;i<8;i++)   
    { HLP.wierzch[i]= sr+obr*wierzch[i]; }
    api->erase_shape(id);
  
    id=api->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> >
			    {{HLP.wierzch[0],HLP.wierzch[1],HLP.wierzch[2],HLP.wierzch[3]},{HLP.wierzch[4],HLP.wierzch[5],HLP.wierzch[6],HLP.wierzch[7]}}, kolor);
  };


  void rotacja(double kat){
    
    MacierzO HLP(obr);
    obr.obrotZ(kat);
    obr=obr*HLP;
  };
  
};

#endif
															
															
