// Soubor 01-09\Napis.h
// Hlavickovy soubor s deklaraci tridy Napis
// Nasledujici dva radky (#ifndef a #define) predstavuji ochranu proti
// moznosti opakovaneho cteni tohoto souboru prekladacem
// (to by zpusobilo problemy)
// zatim to berte jako frazi, kterou se je treba naucit a v niz budete menit
// pouze identifikator _NAPIS_H_ za jiny. Ochrana konci 
#endif na konci souboru
#ifndef _NAPIS_H_
	# define _NAPIS_H_ 

class Napis
{
  public:   	// verejne pristrupne slozky, smi je pouzivat
		 // kterakoli soucast programu

  Napis();  	// Konstruktor bez parametru (konstruktor se vzdy jmenuje
		// stejne jako trida
  Napis(char x[]); // konstruktor s parametrem typu pole znaku
  ~Napis(); 	// Destruktor - jmenuje se vzdy jako trida, navic zacina
		// vzdy znakem "~" a nesmi mit zadne parametry
  void Vypis(); // Vytiskne napis

  private:  // soukrome slozky, smeji je pouzivat pouze metody
	    // teto tridy
  char text[100];   // pole 100 znaku
};

#endif