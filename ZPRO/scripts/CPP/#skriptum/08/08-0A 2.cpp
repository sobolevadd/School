// Soubor 08-0A.CPP
// PREDAVANI UKAZATELE NA FUNKCI JAKO PARAMETRU
// Funkce Integral(a, b, F) spocita obdelnikovym pravidlem
// integral od a do b z funkce F s presnosti radu eps


#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

double eps = 1e-5;		// Pozadovana presnost

double F(double x)      // Jeden integrand
{
 return x*x*x;
}

// Funkce pocitajici urcity integral
// Obe nasledujici hlavicky jsou spravne a znamenaji totez

//double Integral(double a, double b, double f(double))
double Integral(double a, double b, double(* f)(double))
{
 double h = (b-a)/2.0;         // krok
 double stS = HUGE_VAL;        // HUGE_VAL je stand. konstanta (1.797693e308)
 double S = (f(a) + f(a+h))*h; // Prvni priblizeni
 while(fabs(stS - S) > eps)    // Pordrobneji viz na komentar konci
 {
	stS = S;

	S = 0;
	for(double x = a+h/2; x < b; x += h)
		S += f(x);
	S = (S*h +stS)/2;
	h /= 2.0;
 }
 return S;
}

int main()
{
 cout << "Integraly od 0 do PI z funkci sin a cos: " << endl;
 cout << Integral(0.0, PI, sin) << endl;
 cout << Integral(0.0, PI, cos) << endl;
 cout << "Integral z x^3 od 0 do 1: " << endl;
 cout << Integral(0.0, 1.0, &F) << endl;
 return 0;
}

/*

  K integraci podle obdelnikoveho pravidla:
  Interval (a, b) rozdelima na n dilu o delce h = (b-a) / n.
  Integral pak odhadneme souctem h*(f(a+0*h) + f(a+1*h) + f(a+2.h) + ...).

  Jako pocatecni deleni intervalu (a, b) bereme deleni na polovinu,
  tedy s krokem h = (b/a)/2.
  Vypocteme prvni odhad integralu pri tomto deleni, to je (f(a) + f(a+h))*h.
  Vypoctenou hodnotu si zapamatujeme (ulozime do stS) a spocitame novou
  hodnotu s krokem h/2.
  Vypocet konci, jestlize se stara hodnota od nove lisi o mene nez eps.
  Pri vypoctu s polovicnim krokem nepocitame znovu hodnoty f(x)
  integrovane funkce, ktere jsme uz jednou vypocetli. Ty jsou totiz
  v souctu stS. Proto pricteme jen soucet chybejicich hodnot,
  f(a+h/2) + f(a+h/2 + h) + f(a+h/2 + 2h) + ...)
*/