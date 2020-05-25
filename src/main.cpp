#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include"PowierzchniaGorna.hh"
#include"PowierzchniaDolna.hh"
#include"Dron.hh"

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

int Przeszkoda::ile_utworzono=0;
int Przeszkoda::ile_istnieje=0;
int main() {
  drawNS::APIGnuPlot3D  * api= new APIGnuPlot3D(-120,120,-120,120,-120,120,0);
  Wektor<double,3> dr[8],prz[8],s1[12];
  Wektor<double,3> sr,sr_przeszkody,sr_nowydron; 
  MacierzO obr,obr_sr; 
  char wybor;
  double dlugosc;
  double kat;
  uint id,id_przeszkoda;
  int p=0;
  std:: ifstream dron,sr1,prze;



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

  prze.open("Przeszkoda.dat");
  for(int i = 0; i < 12; i++)
    {
      prze >> prz[i];
    };
  prze.close();

  PowierzchniaGorna Tafla(api);
  PowierzchniaDolna Dno(api);
  Tafla.rysuj();
  Dno.rysuj();
  Przeszkoda_Prost P1(api,prz,sr,obr,id_przeszkoda);
  Dron  D(api,dr,s1,sr,obr,id,obr_sr);
  D.rysuj();


  

  
  while(wybor!='e')
	{
	 
	  cout<<"Steruj Dronem opcje:\n";
	  cout<<"w - zmien polozenie\n";
	  cout<<"o - obroc dron po osi Z\n";
	  cout<<"p - dodaj przeszkode prostokatna nr ";
	  cout<<p;
	  cout<<"\n";
	  cout<<"i - ile utworzono przeszkod\n";
	  cout<<"j - ile aktualnie jest przeszkod\n";
	  cout<<"d - dodaj dron\n";
	  cout<<"u - podaj nr przeszkody do usuniecia\n";
	  cout<<"e - zamknij program\n";
	  std::cin >> wybor;

	  cout<<"Wybrales opcje:  ";
	  cout<<wybor;
	  cout<<"\n";
	switch(wybor)
	    {
	    case 'w':
	      std::cout << "Podaj kąt pod jakim dron ma polecieć\n ";
	      std::cin >> kat;
	     std:: cout << "Podaj odleglosc na jaką ma polecieć dron:\n ";
	      std::cin >> dlugosc;
	       D.ruch_animowany(kat,dlugosc);

	      
	      break;
	    case 'o':
	     std:: cout << "Podaj kąt o jaki ma się obrócić dron:\n ";
	      std::cin >> kat;
	      D.rotacja(kat);
	     
	      break;
	    case'p':
	      std::cout<< " Podaj wektor srodka przeszkody:\n";
	      std::cin>>sr_przeszkody;
                 P1.Dodaj_Przeszkode(sr_przeszkody);
	      p++;
	      break;
	    case'd':
	      std::cout<< "Podaj wektor srodka drona:\n";
	      std::cin>>sr_nowydron;
	     
	      break;
	    case'i':
	      std::cout<<"Utworzono ";
	      std::cout<< Przeszkoda::Zwroc_Utworzone();
	      std::cout<<" przeszkod\n";
	     
	      break;
	    case'j':
	      std::cout<<"Istnieje ";
		std::cout<<Przeszkoda::Zwroc_Istniejace();
	      std::cout<<" przeszkod\n";
	      break;
	    case'u':
	      
	      std::cout<<"Usuniento przeszkode";
	      P1.Usun_Przeszkode();
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
