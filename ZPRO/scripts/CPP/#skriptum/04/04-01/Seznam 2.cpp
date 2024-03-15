// Soubor 04-01\Seznam.CPP
// Jednosmerny seznam se zarazkou;
// prvky jsou typu "prvek"

#define LADIM
#include <cstdlib>
#include <iostream>
using namespace std;

#include "typ.h"
#include "prvek.h"
#include "seznam.h"

// Primitivni osetreni chyb pri alokaci
void chyba()
{
 cout << "nedostatek pameti" << endl;
 exit(1);
}

seznam::seznam()		// Konstruktor
: hlava(new(nothrow) prvek), zarazka(0)  // Inicializace pred vstupem do tela konstruktoru
{
 if(!hlava) chyba();		// Konstruktor pouze vytvori zarazku
 else zarazka = hlava;
}

seznam::~seznam()
{
 vyprazdni();			// destruktor vyprazdni seznam a 
 delete hlava;			// odstrani i zarazku
}

void seznam::vyprazdni()	// Odstrani vsechny prvky krome zarazky
{
 while(hlava != zarazka)
 {
   prvek * p = hlava;
   hlava = hlava->GetNext();
   delete p;
 }
}

prvek* seznam::vlozNaKonec(T d) // Vlozi prvek na konec seznamu
{
 prvek *p = new(nothrow) prvek;		
 if(p)				// Pokud se alokace podarila
 {
  zarazka->SetNext(p);		// udela z noveho prvku zarazku
  zarazka->Set(d);		// a do byvale zarazky ulozi nova data
  zarazka = p;
 }
 return p;			// Vrati adresu noveho prvku nebo 0
}

prvek* seznam::najdi(T d, prvek*& pred)
{
 pred = 0;			// Vyhleda prvek a vrati jeho adresu
 zarazka -> Set(d);		// a adresu predchazejiciho prvku (pred)
 prvek*p = hlava;
 while(p->Get() != d)
 {
    pred = p;
    p = p->GetNext();
 }
 if(p == zarazka) return 0;
 else return p;
}

void seznam::vyjmi(T d)
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

