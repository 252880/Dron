#include "Wektor.hh"
#include<iostream>
#include<cmath>



/* Konstruktory */

template<class T, int ROZMIAR>
Wektor<T,ROZMIAR>::Wektor()                           // ustawienie wszystkich skladowych wektora na zera
{

  for(int x=0;x<ROZMIAR;x++)           
    tab[x]=0;
}
 

template<class T, int ROZMIAR>
Wektor<T,ROZMIAR>::Wektor(T *Wtab)           // ustawienie odpowiednich skladowych wektora elementami tablicy
{
  
  for(int x=0;x<ROZMIAR;x++)           
    tab[x]=Wtab[x];
}


/* Metody operatorow arytmetycznych */


 template<class T, int ROZMIAR>
 Wektor<T,ROZMIAR>  Wektor<T,ROZMIAR> :: operator  + (const Wektor<T,ROZMIAR> & W1) const {               // metoda dodajaca dwa wektory, zwracajaca  wektor               
   Wektor<T,ROZMIAR> W;
  for(int x=0;x<ROZMIAR;x++){
    
    W[x]= (*this)[x]+W1[x];
}
  
  return W;
}


 template<class T, int ROZMIAR>
 Wektor<T,ROZMIAR>  Wektor<T,ROZMIAR> :: operator - ( const Wektor<T,ROZMIAR> & W1)const{               // metoda odejmujaca dwa wektory, zwraca wektor
   Wektor<T,ROZMIAR> W;  
  for(int x=0;x<ROZMIAR;x++){
    
    W[x]= (*this)[x]-W1[x];
}

  return W;
}


template<class T, int ROZMIAR>
T Wektor<T,ROZMIAR> :: operator * (const Wektor<T,ROZMIAR> & W1) const{                     // metoda mnozaca dwa wektory, zwraca wektor
  T  i=T(0);

   for(int x=0;x<ROZMIAR;x++){
    
    i= i + (*this)[x]*W1[x];
}

  return i;
}


template<class T, int ROZMIAR>
 Wektor<T,ROZMIAR>  Wektor<T,ROZMIAR> :: operator * ( double li)const{                      // metoda mozaca wektor z liczba typu double, zwraca wektor
  Wektor<T,ROZMIAR> W;

 for(int x=0;x<ROZMIAR;x++){
    
    W[x]= (*this)[x]*li;
}

  return W;
}



template<class T, int ROZMIAR>
Wektor<T,ROZMIAR>  Wektor<T,ROZMIAR> :: operator / ( double li)const{
  
  Wektor<T,ROZMIAR> W;

 for(int x=0;x<ROZMIAR;x++){
    
    W[x]= (*this)[x]/li;
}

  return W;
}
  



 
/* Metody Getter i Setter */

template<class T, int ROZMIAR>
const T & Wektor<T,ROZMIAR> :: operator[] (int index)const { 
  if (index < 0 || index >= ROZMIAR){ 
    std::cerr << "poza zakresem" << std::endl;
    exit(1);
}
  else{
    return this->tab[index];
  }
}

template<class T, int ROZMIAR> 
T & Wektor<T,ROZMIAR> :: operator[] (int index) {


  if (index < 0 || index >= ROZMIAR)
    {
      std::cerr << "poza zakresem" << std::endl;
      exit(1);
    }
  else{
  return this->tab[index];
  }
  }


/*  Przeciazenia in i out */
template<class T, int ROZMIAR>
std::ostream & operator << (std::ostream & strm, const Wektor<T,ROZMIAR> & W1){    // Przeciazenie out wypisuje na ekran skladowe wektora


  for(int i=0;i<ROZMIAR;i++){
    
    strm<<W1[i]<<" ";
}
  return strm;
}

template<class T, int ROZMIAR>
std::istream & operator >> (std::istream & strm, Wektor <T,ROZMIAR> & W1){           // Przeciazenie in pobiera od uzytkownika skladowe wektora

  
  for(int i=0;i<ROZMIAR;i++){
    strm>>W1[i];
  }
  return strm;
}





template<class T , int ROZMIAR>
double Wektor<T,ROZMIAR>::dlugosc() const{

  double i=0;

  for(int x=0;x<ROZMIAR;x++){
    i+=(*this)[x]*(*this)[x];
  }
  i=sqrt(i);

  return i;
}



template class Wektor<double,3>;
template std::istream& operator >> (std::istream &Strm, Wektor<double,3> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,3> & Wek);
