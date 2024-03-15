// Soubor 03-04\HLAVNI.CPP
// pouzije nejakym zpusobem seznam

#include <iostream>
using namespace std;
#include "seznam.h"
void main()
{
	prvek *p; 							// Pomocná promìnná pro hledání
	seznam S;
	for(int i = 0; i < 5; i++)
		if(!(S.vlozNaKonec(i))) chyba();
	cout << ((S.najdi(3,p))? "Je tam" : "není") << endl;
												// Operátor ?: bylo nutno uzávorkovat
	S.vyjmi(2);
}
