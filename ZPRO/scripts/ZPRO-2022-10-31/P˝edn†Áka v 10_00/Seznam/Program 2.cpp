#include "seznam.h"

int main()
{
	Seznam s1;
	vytvor_seznam(s1);
	vloz_na_zacatek(s1, 4);
	vloz_na_zacatek(s1, 5);
	vloz_na_konec(s1, 10);
	odstran_prvni(s1);
	vyprazdni(s1);
}