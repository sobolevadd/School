// Soubor 03-04\PRVEK.H
// Prvek jednosm�rn�ho seznamu

#ifndef _PRVEK_H_
	#define _PRVEK_H_
class prvek
{
public:
	prvek(int d = 0); 			// Konstruktor
	void Set(int d);				// Ulo�en� dat do prvku
	int Get();							// Z�sk�n� dat z prvku
	void SetNext(prvek* p);	// Nastaven� adresy dal��ho prvku
	prvek *GetNext();			// Z�sk�n� ulo�en� adresy dal��ho prvku
private:
	int data;							// U�ite�n� data
	prvek* dalsi; 					// Ukazatel na dal�� prvek seznamu
};


#endif