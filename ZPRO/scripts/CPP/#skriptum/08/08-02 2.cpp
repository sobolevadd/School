// Soubor 08-02.CPP
// Ukazatele na funkce
// Funkce, která vytiskne tabulku 
// zadane funkce (zde tabeluje fci arctg)

#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
void tab(double a, double b, int n, double (*F)(double))
{ 
	double h = (b-a)/n;
 	cout << setiosflags(ios::showpoint);
 	cout << "Tabulka funkce F od " << a << " do " << b << endl;
 	cout << "x" << '\t' << "f(x)" << endl;
 	cout << "------------------" << endl;
 	double x = a;
 	for(int i = 0; i <= n; i++)
 	{
		cout 	<< setprecision(2) << x << "\t" <<setw(8) 
					<< setprecision(6) << F(x) << endl;
		x += h;
 	}
}

void main()
{
	tab(0.0, 1.0, 10, sin);
}


