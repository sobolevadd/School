#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

double f(double x)
{
	return tan(x) - x;
}


void PulInt(double a, double b, double&  x, double eps)      // Procedura p�len� intervalu
{                              // x je ko�en, c je st�ed (a,b)
    double c = (a + b)/2;
    if(abs(b - a)>eps) 
	{
		if(f(a)*f(c) <= 0) PulInt(a, c, x, eps); else PulInt(c, b, x, eps);
	}
    else                            // Rekurzivn� vol�n�, nen�-li spln�na}
        x = c;                      // podm�nka konce
}


int main()
{
	system("CHCP 1250 > NUL");
	double eps = 1e-6,                 // M�ra p�esnosti
		a = 3.2,                       // Meze intervalu, kde hled�me ko�en
		b = 4.7,
		x;                             // hledan� ko�en
	PulInt(a, b, x, eps);
	cout << "Ko�en: " << x << ", f(x) = " << f(x) << endl; 
}