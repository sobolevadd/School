// Soubor 03-04\SEZNAM.CPP
// Implementace metod seznamu
#include <cstdlib>
#include <iostream>

#include "seznam.h"

using namespace std;
// Primitivni ošetøení chyb pøi alokaci
void chyba()
{
	cerr << "Nedostatek pameti" << endl;
	exit(1);					// ukonci program
}
seznam::seznam()					// Konstruktor
{												// Prázdný seznam obsahuje zarážku
	hlava = new(nothrow) prvek(0);
	if(!hlava) chyba();
	else zarazka = hlava;
}
seznam::~seznam()
{
	vyprazdni();						// Destruktor vyprázdní seznam
	delete zarazka;					// a odstraní i zarážku
}
void seznam::vyprazdni()	// Odstraní všechny prvky kromì zarážky
{
	while(hlava != zarazka)
	{
		prvek * p = hlava;
		hlava = hlava->GetNext();
		delete p;
	}
}
prvek* seznam::vlozNaKonec(int d) // Vloží prvek na konec seznamu
{ 
	prvek *p = new(nothrow) prvek(0);
 	if(p) 									// Pokud se alokace podaøila
	{
		zarazka->SetNext(p); 	// udìlá z nového prvku zarážku
 		zarazka->Set(d); 			// a do bývalé zarážky uloží nová data
 		zarazka = p;
 	}
	return p; 							// Vrátí adresu nového prvku nebo 0
}
prvek* seznam::najdi(int d, prvek*& pred)
{												// Vyhledá prvek a vrátí jeho adresu
	pred = 0; 							// a adresu pøedcházejícího prvku 
	zarazka -> Set(d);
	prvek *p = hlava;
	while(p->Get() != d)
	{
		pred = p;
		p = p->GetNext();
	}
	if(p == zarazka) return 0;
	else return p;
}
void seznam::vyjmi(int d)
{
	prvek* pred, *p;
	if(p = najdi(d, pred))
	{
		if(pred)
			pred->SetNext(p->GetNext());
		else
			hlava=p->GetNext();
		delete p;
	}
}
