#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include"PowierzchniaGorna.hh"
#include"PowierzchniaDolna.hh"
#include "Dron.hh"

#include<fstream>




using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}


int main() {
  drawNS::APIGnuPlot3D  * api= new APIGnuPlot3D(-120,120,-120,120,-120,120,-1);
  Wektor<double,3> dr[8],s1[8];
  Wektor<double,3> sr; 
  MacierzO obr,obr_sr; 
  char wybor;
  double dlugosc;
  double kat;
  uint id;
  std:: ifstream dron,sr1;

  

  api->change_ref_time_ms(0);
  dron.open("Dron.dat");
  for(int i = 0; i < 8; i++)
    {
      dron >> dr[i];
    };
  dron.close();

  sr1.open("Sruba1.dat");
  for(int i = 0; i < 12; i++)
    {
      sr1 >> s1[i];
    };
  sr1.close();


  PowierzchniaGorna Tafla(api);
  PowierzchniaDolna Dno(api);
  Tafla.rysuj();
  Dno.rysuj();

  Dron Dro(api,dr,s1,sr,obr,id,obr_sr);
  Dro.rysuj();




  
  while(wybor!='e')
	{

	  cout<<"Steruj Dronem opcje:\n";
	  cout<<"w - zmien polozenie\n";
	  cout<<"q - obroc dron po osi Z\n";
	  cout<<"e - zamknij program\n";
	 
	  std::cin >> wybor;

	  cout<<"Wybrales opcje:  ";
	  cout<<wybor;
	  cout<<"\n";
	switch(wybor)
	    {
	    case 'w':
	      std::cout << "\nPodaj kąt pod jakim dron ma polecieć\n ";
	      std::cin >> kat;
	     std:: cout << "Podaj odleglosc na jaką ma polecieć dron: ";
	      std::cin >> dlugosc;
	       Dro.przemieszczenie(kat,dlugosc);

	      
	      break;
	    case 'q':
	     std:: cout << "Podaj kąt o jaki ma się obrócić dron: ";
	      std::cin >> kat;
	      Dro.rotacja(kat);
	     
	      break;
	    case 'e':
	     std:: cout << "Program zostanie zamknięty\n" << endl;
	      return 0;
	    default:
	      std::cerr << "Nie ma takiej opcji!!\n";
	    }
	};
      
      return 0;
}
