 #ifndef POWIERZCHNIAGORNA_HH
#define POWIERZCHNIAGORNA_HH

#include "Rysuj_Obiekt.hh"
#include "Wektor.hh"






class PowierzchniaGorna : public Rysuj_Obiekt{

public:
  PowierzchniaGorna();

  PowierzchniaGorna(drawNS::APIGnuPlot3D *obiekt) :Rysuj_Obiekt(obiekt){};


    
 
  void rysuj(){
    api->draw_surface(std::vector<std::vector<drawNS::Point3D>>
	 {{drawNS::Point3D(99,99,99), drawNS::Point3D(99,-0,99),drawNS::Point3D(99,-99,99)
         },{
	   drawNS::Point3D(49,99,89),drawNS::Point3D(49,-0,89), drawNS::Point3D(49,-99,89)
         },{
	   drawNS::Point3D(0,99,99), drawNS::Point3D(0,-0,99),drawNS::Point3D(0,-99,99)
	 },{
	   drawNS::Point3D(-49,99,89),drawNS::Point3D(-49,-0,89), drawNS::Point3D(-49,-99,89)
         },{
	   drawNS::Point3D(-99,99,99), drawNS::Point3D(-99,-0,99),drawNS::Point3D(-99,-99,99)}},"blue");

    api->redraw();						  
  };
  
};


#endif
  
