#ifndef INTERFEJS_DRONA_HH
#define INTERFEJS_DRONA_HH

class Interfejs_Drona {
protected:

  
public:

  virtual void ruch_animowany (double kat,double odleglosc)=0;
  virtual MacierzO get_Macierz_Obrotu ()=0;

};

#endif
