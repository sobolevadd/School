// // Soubor 03-04\SEZNAM.H
// deklarace tridy jednosmerneho seznamu se zarazkou
#ifndef _SEZNAM_H_
	#define _SEZNAM_H_

#include "prvek.h"
class seznam
{
public:
	seznam();									// Konstruktor
	~seznam();									// Destruktor
	prvek* vlozNaKonec(int d);	// Vlo�� prvek na konec seznamu
	prvek* vlozZa(prvek* p, int d); 		// Vlo�� nov� prvek za zadan�
	prvek* najdi(int d, prvek* &pred);	// zjist�, zda je prvek 
																	// v seznamu
	void vyjmi(int d);					// Odstran� prvek ze 
														// seznamu (prvn�, kter� obsahuje d)
	int vyjmiPrvni();						// Odstran� prvn� prvek ze seznamu
	void vyprazdni();						// Vypr�zdn� seznam, ponech� zar�ku
private:
	prvek* hlava;							// Ukazatel na hlavu seznamu
	prvek* zarazka;							// Ukazatel na zar�ku
};

void chyba();		// Nejake primitivni osetreni chyby
#endif
