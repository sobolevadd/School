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
	prvek* vlozNaKonec(int d);	// Vloží prvek na konec seznamu
	prvek* vlozZa(prvek* p, int d); 		// Vloží nový prvek za zadaný
	prvek* najdi(int d, prvek* &pred);	// zjistí, zda je prvek 
																	// v seznamu
	void vyjmi(int d);					// Odstraní prvek ze 
														// seznamu (první, který obsahuje d)
	int vyjmiPrvni();						// Odstraní první prvek ze seznamu
	void vyprazdni();						// Vyprázdní seznam, ponechá zarážku
private:
	prvek* hlava;							// Ukazatel na hlavu seznamu
	prvek* zarazka;							// Ukazatel na zarážku
};

void chyba();		// Nejake primitivni osetreni chyby
#endif
