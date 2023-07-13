// Soubor 04-08\Seznam.h
// Implementace seznamu parametrizovaneho
// pomoci sablon
// Neni-li pamet, vyvola konstruktor a metoda 
// VloznaKonec() vyjimku typu bad_alloc
// Pri vyberu z prazdneho seznamu vyvola metoda 
// Vyjni() vyjimku typu logic_error

#ifndef _SEZNAM_H_
 #define _SEZNAM_H_
#include <stdexcept>
#include "prvek.h"
using namespace std;


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
: hlava(0)), zarazka(0)  // Inicializace pred vstupem do tela konstruktoru
{		// Konstruktor pouze vytvori zarazku
	hlava = new prvek<T>; 
	zarazka = hlava;
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
 prvek<T> *p = new prvek<T>;		
 zarazka->SetNext(p);		// udela z noveho prvku zarazku
 zarazka->Set(d);		// a do byvale zarazky ulozi nova data
 zarazka = p;
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
 if(hlava == zarazka) throw logic_error("prazdny seznam");
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