#include <math.h>
#include "Kvadraticka.h"

enum {a, b, c};
reseni Res(double koef[3], double koreny[2])
{
	reseni vysledek;
	if(koef[a] == 0)
	{
		return chyba;
	}
	double d = koef[b]*koef[b] - 4*koef[a]*koef[c];
	if(d < 0)
	{
		vysledek = komplexni;
		d = -d;
	}
	else 
	{
		vysledek = realne;
	}
	d = sqrt(d);
	if(vysledek == realne)
	{
		koreny[0] = (-koef[b] + d)/(2*koef[a]);
		koreny[1] = (-koef[b] - d)/(2*koef[a]);
	}
	else
	{
		koreny[0] = -koef[b]/(2*koef[a]);
		koreny[1] = d/(2*koef[a]);
	}
	return vysledek;
}
