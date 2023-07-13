// Soubor 04-01\Seznam.h
// Implementace seznamu parametrizovaneho
// pomoci typedef
// NENI TO VHODNE RESENI, POKUD JSOU SABLONY

#ifndef _SEZNAM_H_
 #define _SEZNAM_H_
#include "typ.h"
#include "prvek.h"

class seznam
{
  prvek* hlava;      // ukazatel na hlavu seznamu
  prvek* zarazka;    // ukazatel na zarazku
 public:
 seznam();	     // konstruktor
 ~seznam();          // destruktor
 prvek* vlozNaKonec(T d);          // vlozi prvek na konec seznamu
 prvek* najdi(T d, prvek* &pred);  // zjisti, zda je prvek v seznamu
 void vyjmi(T d);		   // odstrani prvek ze seznamu (prvni, ktery obsahuje d)
 void vyprazdni();		   // vyprazdni seznam, ponecha zarazku
};

void chyba();

#endif