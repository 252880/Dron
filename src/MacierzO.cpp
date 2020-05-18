#include "MacierzO.hh"


MacierzO MacierzO:: obrotX(double kat){
double rad=kat*3.14/180;  
  
  
      tab[1][1]=cos(rad);                
      tab[1][2]=sin(rad);
      tab[2][1]=-sin(rad);
      tab[2][2]=cos(rad);
      tab[0][2]=0;
      tab[0][1]=0;
      tab[2][0]=0;
      tab[1][0]=0;
      tab[0][0]=1;

      return (*this);
}

MacierzO MacierzO :: obrotY(double kat){
  double rad=kat*3.14/180;
 
  
      tab[2][2]=cos(rad);
      tab[2][0]=sin(rad);
      tab[0][2]=-sin(rad);
      tab[0][0]=cos(rad);
      tab[1][0]=0;
      tab[2][1]=0;
      tab[0][1]=0;
      tab[1][2]=0;
      tab[1][1]=1;

      return (*this);
}

MacierzO MacierzO:: obrotZ(double kat){
  double rad=kat*3.14/180;  
      

      tab[0][0]=cos(rad);
      tab[1][0]=-sin(rad);
      tab[0][1]=sin(rad);
      tab[1][1]=cos(rad);
      tab[2][0]=0;
      tab[2][1]=0;
      tab[0][2]=0;
      tab[1][2]=0;
      tab[2][2]=1;

      return (*this);
    }
