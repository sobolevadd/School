#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

double f(double x)
{
	return tan(x) - x;
}

void Rozhodni(double a, double b, double c, double& x, double eps); 

void PulInt(double a, double b, double& x, double eps)         // Metoda p�len� intervalu
{                                       
    double c = (a + b)/2;	                                   // St�ed intervalu (a,b)
    if(abs(b - a)>eps)
	{                                                          // V�po�et skon��, je-li inter
        Rozhodni(a, b, c, x, eps);                             // val (a,b), v n�m� ko�en le��,
	}
    else                                                       // krat�� ne� eps
        x = c;                                                 // P�i�azen� v�sledku
}

void Rozhodni(double a, double b, double c, double& x, double eps)
{
    if(f(a)*f(c) <= 0) 
		PulInt(a, c, x, eps);
	else 
		PulInt(c, b, x, eps);
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