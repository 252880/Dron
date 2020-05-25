#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH

#include "Figura3D.hh"

class Graniastoslup6 : public Figura3D {
protected:

  Wektor<double,3> wierzch[12];

public:

  Graniastoslup6();
  Graniastoslup6(drawNS::APIGnuPlot3D *obiekt, Wektor<double,3> *x, Wektor<double,3> &sr, MacierzO & obr,uint & id) : Figura3D(obiekt,sr,obr,id)
  {
    for(int i=0;i<12;i++)
      wierzch[i]=x[i];
  };

  void  rysuj(){
    
         Graniastoslup6 HLP(*this);
  for(int i=0;i<12;i++)
    { HLP.wierzch[i]= sr+obr*wierzch[i]; }


    id=api->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> >
			    {{HLP.wierzch[0],HLP.wierzch[1],HLP.wierzch[2],HLP.wierzch[3],HLP.wierzch[4],HLP.wierzch[5]
			    },{
				 HLP.wierzch[6],HLP.wierzch[7],HLP.wierzch[8],HLP.wierzch[9],HLP.wierzch[10],HLP.wierzch[11]}},"red");

    api->redraw();
  };

  
};
#endif
