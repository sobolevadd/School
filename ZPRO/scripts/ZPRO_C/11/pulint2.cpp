#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

double f(double x)
{
	return tan(x) - x;
}


void PulInt(double a, double b, double&  x, double eps)      // Procedura pùlení intervalu
{                              // x je koøen, c je støed (a,b)
    double c = (a + b)/2;
    if(abs(b - a)>eps) 
	{
		if(f(a)*f(c) <= 0) PulInt(a, c, x, eps); else PulInt(c, b, x, eps);
	}
    else                            // Rekurzivní volání, není-li splnìna}
        x = c;                      // podmínka konce
}


int main()
{
	system("CHCP 1250 > NUL");
	double eps = 1e-6,                 // Míra pøesnosti
		a = 3.2,                       // Meze intervalu, kde hledáme koøen
		b = 4.7,
		x;                             // hledaný koøen
	PulInt(a, b, x, eps);
	cout << "Koøen: " << x << ", f(x) = " << f(x) << endl; 
}