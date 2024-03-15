#ifndef __SEZNAM_H__
#define __SEZNAM_H__

using T = int;
//typedef int T;

const T NULA = 0;

struct prvek
{
	T data;
	prvek* dalsi;
};

struct seznam
{
	prvek* hlava;
	prvek* zarazka;
	size_t velikost;
};

void vytvor(seznam& s);
void vloz_na_zacatek(seznam& s, T co);
void vloz_na_konec(seznam& s, T co);
void odstran_prvni(seznam& s);
#endif // !__SEZNAM_H__

