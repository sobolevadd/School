// Soubor 15-00C.cpp
// Operator indexovani v jednoduchem pripade
// ukazuje definici pro konstanty i nekonstanty

#include <stdexcept>
#include <iostream>
using namespace std;

class bod {
	double s[3]; 										// Zapouzdøené pole
public:
	bod(double = 0, double = 0, double = 0);
	double& operator[](int); 					// Operátor indexování
	double operator[](int) const;			// Indexování pro konstanty
};
	bod::bod(double x, double y, double z)
{	s[0] = x; s[1] = y; s[2] = z;
}
	double& bod::operator[](int i)
{
	if((i < 1) || (i > 3))throw runtime_error("index mimo meze"); 		// Kontrola indexu
	return s[i-1]; 									// Posunutí mezí indexu
}

double bod::operator[](int i) const
{
	if((i < 1) || (i > 3)) throw runtime_error("index mimo meze"); 	// Kontrola indexu
	return s[i-1]; 									// Posunutí mezí indexu
}

int main()
{
	bod a(3.1, 5.2, 5.5), b;
	const bod c(1.1, 2.2, 3.3);

	b[1] = a[3];	// Pouzije se operator pro nekonst. instance
	double x = c[2];// Pouzije se operator pro konst. instance
	//c[3] = 11.22;	// Nelze
}