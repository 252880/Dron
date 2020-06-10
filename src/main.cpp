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
  std::vector<std::shared_ptr<Przeszkoda> > Kolekcja_Przeszkod;
  std::vector<std::shared_ptr<Interfejs_Drona> > Kolekcja_Dronow;

  

  Wektor<double,3> dr[8],dr1[8],dr2[8],prz[8],prz1[8],prz2[8],prz3[8],prz4[8],prz5[8],s1[12];
  Wektor<double,3> sro,sr_nowydron; 
  MacierzO obr,obr1,obr2,obr_sr; 
  char wybor;
  double odleglosc;
  double kat;
  uint id;
  int p=0;
  

  std:: ifstream dron,dron1,dron2,sr1,prze,prze1,prze2,prze3,prze4,prze5;



  dron.open("Dron.dat");
  for(int i = 0; i < 8; i++)
    {
      dron >> dr[i];
    };
  dron.close();

  
  dron1.open("Dron1.dat");
  for(int i = 0; i < 8; i++)
    {
      dron1 >> dr1[i];
    };
  dron1.close();

  dron2.open("Dron2.dat");
  for(int i = 0; i < 8; i++)
    {
      dron2 >> dr2[i];
    };
  dron2.close();

  sr1.open("Sruba1.dat");
  for(int i = 0; i < 12; i++)
    {
      sr1 >> s1[i];
    };
  sr1.close();

  prze.open("Przeszkoda.dat");
  for(int i = 0; i < 8; i++)
    {
      prze >> prz[i];
    };
  prze.close();

    prze1.open("Przeszkoda1.dat");
  for(int i = 0; i < 8; i++)
    {
      prze1 >> prz1[i];
    };
  prze1.close();

    prze2.open("Przeszkoda2.dat");
  for(int i = 0; i < 8; i++)
    {
      prze2 >> prz2[i];
    };
  prze2.close();

    prze3.open("Przeszkoda3.dat");
  for(int i = 0; i < 8; i++)
    {
      prze3 >> prz3[i];
    };
  prze3.close();

    prze4.open("Przeszkoda4.dat");
  for(int i = 0; i < 8; i++)
    {
      prze4 >> prz4[i];
    };
  prze4.close();

    prze5.open("Przeszkoda5.dat");
  for(int i = 0; i < 8; i++)
    {
      prze5 >> prz5[i];
    };
  prze5.close();

  std::shared_ptr <Przeszkoda_Prost>  P(new Przeszkoda_Prost(api,prz,"black",sro,obr,id));
  std::shared_ptr <Przeszkoda_Prost>  P1(new Przeszkoda_Prost(api,prz1,"black",sro,obr,id));

  std::shared_ptr <Przeszkoda_Prost>  P2(new Przeszkoda_Prost(api,prz2,"black",sro,obr,id));
  std::shared_ptr <Przeszkoda_Prost>  P3(new Przeszkoda_Prost(api,prz3,"black",sro,obr,id));

  std::shared_ptr <Przeszkoda_Prost>  P4(new Przeszkoda_Prost(api,prz4,"black",sro,obr,id));
  std::shared_ptr <Przeszkoda_Prost>  P5(new Przeszkoda_Prost(api,prz5,"black",sro,obr,id));
  

  Kolekcja_Przeszkod.push_back(P); 
  Kolekcja_Przeszkod.push_back(P1);

  Kolekcja_Przeszkod.push_back(P2); 
  Kolekcja_Przeszkod.push_back(P3);


  Kolekcja_Przeszkod.push_back(P4); 
  Kolekcja_Przeszkod.push_back(P5);


  std::shared_ptr <Dron>  D(new Dron(api,dr,"black",s1,sro,obr,id,obr_sr));
  std::shared_ptr <Dron>  D1(new Dron(api,dr1,"blue",s1,sro,obr,id,obr_sr));
  std::shared_ptr <Dron>  D2(new Dron(api,dr2,"green",s1,sro,obr,id,obr_sr));



  Kolekcja_Dronow.push_back(D); 
  Kolekcja_Dronow.push_back(D1);
  Kolekcja_Dronow.push_back(D2); 
  



  for(auto elem : Kolekcja_Dronow){
    elem->rysuj();
  }
  

  PowierzchniaGorna Tafla(api);
  PowierzchniaDolna Dno(api);
  
  Dno.rysuj(); 
  Tafla.rysuj();



  for(auto elem : Kolekcja_Przeszkod){
  elem->Dodaj_Przeszkode();
  }

  

  
  while(wybor!='e')
	{
 		 
	  cout<<"Steruj Dronem opcje:\n\n";
	  cout<<" Dron 0 -black\n Dron 1 - blue\n Dron 2 - green\n\n";
	  cout<<"Sterujesz dronem nr ";
	  cout<<p;
	  cout<<"\n\n";
	  cout<<"w - zmien polozenie\n";
	  cout<<"o - obroc dron po osi Z\n";
	  cout<<"j - ile aktualnie jest przeszkod\n";
          cout<<"d - wybierz drona do sterowania\n";
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
	      std::cin >> odleglosc;
	      for(int i=0;i<100;i++){
		 Kolekcja_Dronow[p]->ruch_animowany(kat,odleglosc/100);
	       for(auto elem :Kolekcja_Przeszkod){
	       elem->Czy_Kolizja(*Kolekcja_Dronow[p]);
	       }

	       Tafla.Czy_Kolizja(*Kolekcja_Dronow[p]);
	       Dno.Czy_Kolizja(*Kolekcja_Dronow[p]);
	       
	       
	      }   
	      
	      break;
	    case 'o':
	     std:: cout << "Podaj kąt o jaki ma się obrócić dron:\n ";
	      std::cin >> kat;
	      Kolekcja_Dronow[p]->rotacja(kat);
	     
	      break;
	                   
	      case'd':
	      std::cout<< "Podaj nr drona, ktorym chcesz sterowac\n";
	      std::cin>>p;
	     
	      break;
	    case'j':
	      std::cout<<"Istnieje ";
		std::cout<<Przeszkoda::Zwroc_Istniejace();
	      std::cout<<" przeszkod\n";
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
