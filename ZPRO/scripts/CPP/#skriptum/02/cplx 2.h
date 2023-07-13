// Soubor cplx.h
// Prvni priklad na pretezovani operatoru
// Definujeme tridu cplx pro praci s komplexnimi cisly
// a pretizene operatory << a >> pro vstup a vystup
// komplexnich cisel

#include <iostream>
using namespace std;
static inline double SQR(double x) {return x*x;}   // funkce pro vypocet druhe mocniny

class cplx
{
  public:
   double Re() { return re; } // vrati realnou cast
   double Im() { return im; } // vrati imaginarni cast
   // konstruktor s implicitnimi hodnotami parametru:
   cplx(double r = 0, double i = 0);
   // pretizeny operator + pro scitani komplexnich cisel:
   cplx operator+(cplx c);
   // pretizeny operator - pro odcitani komplexnich cisel:
   cplx operator-(cplx c);
   // pretizeny operator * pro nasobeni komplexnich cisel:
   cplx operator*(cplx c);
   // pretizeny operator / pro deleni komplexnich cisel:
   cplx operator/(cplx c);
   // pretizeny unarni operator - (otoci znamenko):
   cplx operator-();
	
  private:
   double re, im;
};

ostream& operator<<(ostream& Str, cplx c);
istream& operator>>(istream& Str, cplx &c);