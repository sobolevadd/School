// Soubor 03-04\HLAVNI.CPP
// pouzije nejakym zpusobem seznam

#include <iostream>
using namespace std;
#include "seznam.h"
void main()
{
	prvek *p; 							// Pomocn� prom�nn� pro hled�n�
	seznam S;
	for(int i = 0; i < 5; i++)
		if(!(S.vlozNaKonec(i))) chyba();
	cout << ((S.najdi(3,p))? "Je tam" : "nen�") << endl;
												// Oper�tor ?: bylo nutno uz�vorkovat
	S.vyjmi(2);
}
