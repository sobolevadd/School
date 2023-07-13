// Soubor 03-04\Prvek.CPP
// implementace metod prvku seznamu
#include "prvek.h"

prvek::prvek(int d) 			// Konstruktor tøídy prvek
: data(d), dalsi(0)
{}

void prvek::Set(int d) 				// Uložení dat do prvku
{
	data = d;
}
int prvek::Get()							// Získání dat z prvku
{
	return data;
}
void prvek::SetNext(prvek* p)	// Nastavení adresy dalšího prvku
{
	dalsi = p;
}
// Získání uložené adresy dalšího prvku seznamu
prvek* prvek::GetNext()
{
	return dalsi;
}
