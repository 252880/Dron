#ifndef INTERFEJS_DRONA_HH
#define INTERFEJS_DRONA_HH

class Interfejs_Drona {
protected:

  
public:

  virtual void ruch_animowany (double kat,double odleglosc)=0;
  virtual Wektor<double,3> get_srodek ()const=0;
  virtual Wektor<double,3> get_wierzch()const=0;
  virtual void rysuj()=0;
  virtual void rotacja(double kat)=0;
  
};

#endif
