#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

double f(double x)
{
	return tan(x) - x;
}

void Rozhodni(double a, double b, double c, double& x, double eps); 

void PulInt(double a, double b, double& x, double eps)         // Metoda pùlení intervalu
{                                       
    double c = (a + b)/2;	                                   // Støed intervalu (a,b)
    if(abs(b - a)>eps)
	{                                                          // Výpoèet skonèí, je-li inter
        Rozhodni(a, b, c, x, eps);                             // val (a,b), v nìmž koøen leží,
	}
    else                                                       // kratší než eps
        x = c;                                                 // Pøiøazení výsledku
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
	double eps = 1e-6,                 // Míra pøesnosti
		a = 3.2,                       // Meze intervalu, kde hledáme koøen
		b = 4.7,
		x;                             // hledaný koøen
	PulInt(a, b, x, eps);
	cout << "Koøen: " << x << ", f(x) = " << f(x) << endl; 
}