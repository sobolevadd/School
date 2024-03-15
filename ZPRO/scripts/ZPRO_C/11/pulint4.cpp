#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

double fce(double x)
{
	return tan(x) - x;
}


void PulInt(double (*f)(double), double a, double b, double & x, double eps)
{                                      // Nerekurzivní verze
    while(abs(b - a)>eps)                          // Podmínka konce
	{
        x = (a + b)/2;
        if(f(a)*f(x) < 0) b = x; else a = x;        // Urèení nových mezí
	}                                            // intervalu
}


int main()
{
	system("CHCP 1250 > NUL");
	double eps = 1e-6,                 // Míra pøesnosti
		a = 3.2,                       // Meze intervalu, kde hledáme koøen
		b = 4.7,
		x;                             // hledaný koøen
	PulInt(fce, a, b, x, eps);
	cout << "Koøen: " << x << ", fce(x) = " << fce(x) << endl; 
}