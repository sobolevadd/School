// Soubor 04-01\Prvek.h
// Prvek jednozmerneho seznamu parametrizovaneho
// pomoci typedef 
// NENI TO VHODNE RESENI, POKUD JSOU SABLONY		

#ifndef _PRVEK_H_
 #define _PRVEK_H_
#include "typ.h"

class prvek
{
  T data;			// uzitecna data
  prvek* dalsi;			// dalsi prvek seznamu
 public:
  prvek(T d = 0) :data(d), dalsi(0) {} // konstruktor
  void Set(T d) { data = d; }	       // Ulozeni dat do prvku	
  T Get() { return data; }	       // ziskani dat z prvku
  void SetNext(prvek* p) {dalsi = p;}  // Nastaveni adresy dalsiho prvku
  prvek *GetNext() { return dalsi; }   // Ziskani ulozene adresy dalsiho prvku
};

#endif