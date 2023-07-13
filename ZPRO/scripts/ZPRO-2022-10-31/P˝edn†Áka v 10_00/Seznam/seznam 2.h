#ifndef __SEZNAM_H__
#define __SEZNAM_H__

using T = int;
const T NULA = 0;

//typedef int T;

struct Prvek
{
	T data;
	Prvek* dalsi;
};

struct Seznam
{
	Prvek* hlava;
	Prvek* zarazka;
	size_t velikost;
};

void vytvor_seznam(Seznam& s);
void vloz_na_zacatek(Seznam& s, T co);
void vloz_na_konec(Seznam& s, T co);
void odstran_prvni(Seznam& s);
void vyprazdni(Seznam& s);
bool prazdny(Seznam& s);
size_t velikost_seznamu(Seznam& s);
void zrus(Seznam& s);


#endif // __SEZNAM_H__
