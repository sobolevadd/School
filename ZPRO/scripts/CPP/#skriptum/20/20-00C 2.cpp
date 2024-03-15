// Soubor 20-00C.cpp
// Pouziti manipulatoru - tisk tabulky funkce


#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

void tab(double (*F)(double), double Od, double Do,
				 int Kolik, ostream& Proud, const char *Jmeno)
{
	const int w = 10;
	Proud << "Tabulka funkce " << Jmeno << endl;
	Proud << "---------------";
	for(int i = 0; i < strlen(Jmeno); i++) Proud << '-';
	Proud << endl;
	double krok = (Do-Od)/Kolik;
	long flags = Proud.flags();
	long prec = Proud.precision();
	Proud 	<< setprecision(5) 
				<< setiosflags(ios::showpoint|ios::right);
	Proud 	<< setw(w) << "x" << setw(w-3) << Jmeno 
				<< "(x)" << endl;
	double x = Od;
	for(i=0; i < Kolik+1; i++)
 	{
		Proud << setw(w) << x << setw(w) << F(x) <<endl;
 		x += krok;
	}
	Proud << setprecision(prec);
	Proud.flags(flags);
}


int main()
{
	tab(sin, 0, 1, 11, cout, "sin");
}