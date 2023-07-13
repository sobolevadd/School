// priklad na definici vystupniho
// operatoru pro uzivatelem definovany objektovy typ
// a definici manipulatoru bez parametru

#include <iomanip.h>

// trida compl
class comp{
  double re, im;
 public:
  comp(double r=0, double i=0):re(r), im(i){}
// operator jako spratelena funkce
  friend ostream& operator<<(ostream &o, comp &c);
};

// vystupni operator musi:
//-  vracet referenci na ostream
//- mit prvni parametr typu &ostream (predavany odkazem)
//- musi vratit odkaz na proud, ktery dostane jako parametr

ostream & operator<< (ostream &o, comp &c){
 int w = o.width();
 cout << c.re << ' ' << setw(w) << c.im;
 return o;
};

// manipulator, ktery pipne:
// manitupator bez parametru na vystupnim proudu:
// funkce, ktera vraci referenci na proud, ktery dostane jako vstupni
// parametr (odkazem)
// a krome toho provede pozadovanou cinnost - zde vlozi do proudu 
// znak '\a' (alert - pipnuti)

ostream& beep(ostream& o){
 o << '\a';
 return o;
}

comp c1(1), i(0,1);

int main(){
 cout << beep << setw(10) << c1<< endl << i;
 return 0;
}