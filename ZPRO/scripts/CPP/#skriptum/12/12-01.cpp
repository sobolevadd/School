// Soubor 12-01.CPP
// priklad na pouziti vypustky
// funkce max pocita maximum z libovolneho poctu n celych cisel
// ma n+1 parametru;
// prvni z nich udava pocet ciseel, z nichz pocitame maximum
// dalsi parametry jsou cisla, z nichz pocitame maximum
// prvni parametr se predava jako pevny, dalsi pomoci  vypustky


#include <stdarg.h>
#include <iostream>
#include <float.h>
using namespace std;

double Max(int i, ...)
{
	double s = -DBL_MAX,t; 	// Inicializace nejmenší možnou hodnotou
	int j;					// definovanou v <float.h>
	va_list ap; 						// ap je ukazatel na pole parametrù
	va_start(ap,i); 				// Inicializace ukazatele ap
	for(j=1;j<=i;j++)
	{
		t = va_arg(ap,double);// V cyklu získáváme hodnoty parametrù
		if(t>s)s = t;
	}
	va_end(ap);						// Závìreèný úklid
	return s;
}

int main()
{
	cout << "maximum z danych cisel je " << Max(5, 3.1, 6.0, -22.1, 87.9, 0.1) << endl;
	cout << "maximum z druhe serie je " << Max(3, -654.0, 9.9, -22.3) << endl;
}

/*
  Pozor:
  - Pri predavani parametru pomoci vypustky se nekontroluje
	 pocet a typ predanych paramwetru.
  - parametry typu short, unsigned short, char, signed char, unsigned char,
	 enum a bitova pole se konvertuji na int resp. unsigned int, float se
	 konvertuje na double - to znamena, ze parametry uvedenych typu nelze
	 pomoci vypustky predat!
*/