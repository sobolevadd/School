// Soubor 04-02\Seznam.h
// Implementace seznamu parametrizovaneho
// pomoci typedef
// NENI TO VHODNE RESENI, POKUD JSOU SABLONY

#ifndef _SEZNAM_H_
 #define _SEZNAM_H_
#include "prvek.h"

template<typename T>
class seznam
{
  prvek<T>* hlava;      // ukazatel na hlavu seznamu
  prvek<T>* zarazka;    // ukazatel na zarazku
 public:
 seznam();	     // konstruktor
 ~seznam();          // destruktor
 prvek<T>* vlozNaKonec(T d);          // vlozi prvek na konec seznamu
 prvek<T>* najdi(T d, prvek<T>* &pred);  // zjisti, zda je prvek v seznamu
 void vyjmi(T d);		   // odstrani prvek ze seznamu (prvni, ktery obsahuje d)
 void vyprazdni();		   // vyprazdni seznam, ponecha zarazku
};

void chyba();
// Jednosmerny seznam se zarazkou;
// prvky jsou typu "prvek"

#define LADIM
#include <cstdlib>
#include <iostream>
using namespace std;

#include "prvek.h"
#include "seznam.h"

void chyba();

template<typename T>
seznam<T>::seznam()		// Konstruktor
: hlava(new(nothrow) prvek<T>), zarazka(0)  // Inicializace pred vstupem do tela konstruktoru
{
 if(!hlava) chyba();		// Konstruktor pouze vytvori zarazku
 else zarazka = hlava;
}


template<typename T>
seznam<T>::~seznam()
{
 vyprazdni();			// destruktor vyprazdni seznam a 
 delete hlava;			// odstrani i zarazku
}

template<typename T>
void seznam<T>::vyprazdni()	// Odstrani vsechny prvky krome zarazky
{
 while(hlava != zarazka)
 {
   prvek<T> * p = hlava;
   hlava = hlava->GetNext();
   delete p;
 }
}

template<typename T>
prvek<T>* seznam<T>::vlozNaKonec(T d) // Vlozi prvek na konec seznamu
{
 prvek<T> *p = new(nothrow) prvek<T>;		
 if(p)				// Pokud se alokace podarila
 {
  zarazka->SetNext(p);		// udela z noveho prvku zarazku
  zarazka->Set(d);		// a do byvale zarazky ulozi nova data
  zarazka = p;
 }
 return p;			// Vrati adresu noveho prvku nebo 0
}

template<typename T>
prvek<T>* seznam<T>::najdi(T d, prvek<T>*& pred)
{
 pred = 0;			// Vyhleda prvek a vrati jeho adresu
 zarazka -> Set(d);		// a adresu predchazejiciho prvku (pred)
 prvek<T>*p = hlava;
 while(p->Get() != d)
 {
    pred = p;
    p = p->GetNext();
 }
 if(p == zarazka) return 0;
 else return p;
}

template<typename T>
void seznam<T>::vyjmi(T d)
{
 prvek<T>* pred, *p;
 if(p = najdi(d, pred))
 {
  if(pred)
   pred->SetNext(p->GetNext());
  else
    hlava=p->GetNext();
  delete p;
 }
}



#endif