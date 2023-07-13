// Soubor 04-02\Prvek.h
// Prvek jednozmerneho seznamu parametrizovaneho
// pomoci sablon
// Mate-li starsi prekladac, bude treba klicove slovo
// typename nahradit slovem class

#ifndef _PRVEK_H_
 #define _PRVEK_H_

template<typename T>
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