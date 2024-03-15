#include "napis.h"

int napis::pocitadlo = 0;

napis::napis(char *zadani)
{
	nastav(zadani);
	pocitadlo++;
}

napis::~napis()
{
	pocitadlo--;
}

int napis::pocetNapisu()
{
	return pocitadlo;
}