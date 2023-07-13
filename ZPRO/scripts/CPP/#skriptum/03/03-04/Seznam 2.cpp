// Soubor 03-04\SEZNAM.CPP
// Implementace metod seznamu
#include <cstdlib>
#include <iostream>

#include "seznam.h"

using namespace std;
// Primitivni o�et�en� chyb p�i alokaci
void chyba()
{
	cerr << "Nedostatek pameti" << endl;
	exit(1);					// ukonci program
}
seznam::seznam()					// Konstruktor
{												// Pr�zdn� seznam obsahuje zar�ku
	hlava = new(nothrow) prvek(0);
	if(!hlava) chyba();
	else zarazka = hlava;
}
seznam::~seznam()
{
	vyprazdni();						// Destruktor vypr�zdn� seznam
	delete zarazka;					// a odstran� i zar�ku
}
void seznam::vyprazdni()	// Odstran� v�echny prvky krom� zar�ky
{
	while(hlava != zarazka)
	{
		prvek * p = hlava;
		hlava = hlava->GetNext();
		delete p;
	}
}
prvek* seznam::vlozNaKonec(int d) // Vlo�� prvek na konec seznamu
{ 
	prvek *p = new(nothrow) prvek(0);
 	if(p) 									// Pokud se alokace poda�ila
	{
		zarazka->SetNext(p); 	// ud�l� z nov�ho prvku zar�ku
 		zarazka->Set(d); 			// a do b�val� zar�ky ulo�� nov� data
 		zarazka = p;
 	}
	return p; 							// Vr�t� adresu nov�ho prvku nebo 0
}
prvek* seznam::najdi(int d, prvek*& pred)
{												// Vyhled� prvek a vr�t� jeho adresu
	pred = 0; 							// a adresu p�edch�zej�c�ho prvku 
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
