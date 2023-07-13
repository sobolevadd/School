#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

double fce(double x)
{
	return tan(x) - x;
}


void PulInt(double (*f)(double), double a, double b, double & x, double eps)
{                                      // Nerekurzivn� verze
    while(abs(b - a)>eps)                          // Podm�nka konce
	{
        x = (a + b)/2;
        if(f(a)*f(x) < 0) b = x; else a = x;        // Ur�en� nov�ch mez�
	}                                            // intervalu
}


int main()
{
	system("CHCP 1250 > NUL");
	double eps = 1e-6,                 // M�ra p�esnosti
		a = 3.2,                       // Meze intervalu, kde hled�me ko�en
		b = 4.7,
		x;                             // hledan� ko�en
	PulInt(fce, a, b, x, eps);
	cout << "Ko�en: " << x << ", fce(x) = " << fce(x) << endl; 
}