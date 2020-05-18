#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include"Dr3D_gnuplot_api.hh"

template <class T, int ROZMIAR>
class Wektor {
protected:
  T tab[ROZMIAR];

public:

  Wektor ();
 
  Wektor(double x, double y, double z){tab[0]=x; tab[1]=y; tab[2]=z;};


   Wektor(T *Wtab);
   
  Wektor<T,ROZMIAR> operator + (const  Wektor<T,ROZMIAR> & W1) const;
  Wektor<T,ROZMIAR>  operator - (const Wektor<T,ROZMIAR> & W1)const;
  T operator * (const Wektor<T,ROZMIAR> & W1)const;
  Wektor<T,ROZMIAR>  operator *  (double li)const;
  Wektor<T,ROZMIAR> operator /(double li)const;
  
  double dlugosc() const; 

  const T & operator [] (int index) const;
  T & operator [] (int index);

  operator drawNS::Point3D(){return drawNS::Point3D(tab[0],tab[1], tab[2]);}


  
};
  



  template <class T, int ROZMIAR>
  std::istream& operator >> (std::istream &strm, Wektor<T,ROZMIAR> &W1);


  template <class T, int ROZMIAR>
  std::ostream& operator << (std::ostream &strm, const Wektor<T,ROZMIAR> &W1); 


 

#endif
