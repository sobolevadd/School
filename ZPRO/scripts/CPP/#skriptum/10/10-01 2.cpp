// Soubor 10-01.CPP
// Priklad standardnich konverzi a 
// jejich neprenositelnosti
// Prelozite-li to v 32bitoven prostøedi na PC, zavola 
// se f(int)
// ztimco v 16bitoben prostredi (napr. Borland C++ 3.1)
// se zavola f(unsigned)

// Ve starsich prekladacich (napr. zmineny BC++ 3.1)
// je treba napsat <iostream.h> a odstranit radek 
// s direktivou using namespace std;

#include <iostream>
using namespace std;
unsigned short us = 65535;
void f(int)
{ 
	cout << "volá se f(int)";
}
void f(unsigned)
{ 
	cout << "volá se f(unsigned)";
}
int main()
{
	unsigned short us = 65535;
	f(+us);
	return 0;
}
