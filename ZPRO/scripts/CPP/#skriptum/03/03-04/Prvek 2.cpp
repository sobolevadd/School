// Soubor 03-04\Prvek.CPP
// implementace metod prvku seznamu
#include "prvek.h"

prvek::prvek(int d) 			// Konstruktor t��dy prvek
: data(d), dalsi(0)
{}

void prvek::Set(int d) 				// Ulo�en� dat do prvku
{
	data = d;
}
int prvek::Get()							// Z�sk�n� dat z prvku
{
	return data;
}
void prvek::SetNext(prvek* p)	// Nastaven� adresy dal��ho prvku
{
	dalsi = p;
}
// Z�sk�n� ulo�en� adresy dal��ho prvku seznamu
prvek* prvek::GetNext()
{
	return dalsi;
}
