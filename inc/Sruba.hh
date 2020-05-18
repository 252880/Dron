#ifndef SRUBA_HH
#define SRUBA_HH

#include "Prostopadloscian.hh"

class Sruba : public Prostopadloscian {
protected:
  MacierzO o;      

public:

  Sruba();
  Sruba(drawNS::APIGnuPlot3D *obiekt, Wektor<double,3> *x, Wektor<double,3> &sr, MacierzO & obr,uint & id,MacierzO &os) : Prostopadloscian(obiekt,x,sr,obr,id), o(os) 
  {
    for(int i=0;i<8;i++)
      wierzch[i]=x[i];
  }

  void  rysuj(Wektor<double,3> x){
   
    Sruba HLP(*this);
    for(int i = 0; i < 8; i++)
      {
	HLP.wierzch[i] =  x +obr*o*wierzch[i];
      }
    id=api->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>>
		      {{HLP.wierzch[0],HLP.wierzch[1],HLP.wierzch[2],HLP.wierzch[3]
		      },{
			HLP.wierzch[4],HLP.wierzch[5],HLP.wierzch[6],HLP.wierzch[7]}});
  api->redraw();
  };

  void usun(){
    api->erase_shape(id);
  }

  void rotacja(double kat){
    api->erase_shape(id);
    MacierzO HLP(obr);
 
    obr.obrotZ(kat);
    obr=obr*HLP;
  
  };
void obrot(){
  api->erase_shape(id);
  MacierzO HLP(o);
  o.obrotX(45);

  o=o*HLP;
}  
};

#endif



