// Soubor 03-04\PRVEK.H
// Prvek jednosmìrného seznamu

#ifndef _PRVEK_H_
	#define _PRVEK_H_
class prvek
{
public:
	prvek(int d = 0); 			// Konstruktor
	void Set(int d);				// Uložení dat do prvku
	int Get();							// Získání dat z prvku
	void SetNext(prvek* p);	// Nastavení adresy dalšího prvku
	prvek *GetNext();			// Získání uložené adresy dalšího prvku
private:
	int data;							// Užiteèná data
	prvek* dalsi; 					// Ukazatel na další prvek seznamu
};


#endif