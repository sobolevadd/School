#include "seznam.h"

void vytvor_seznam(Seznam& s)
{
	s.hlava = s.zarazka = new Prvek{ NULA, nullptr };
	s.velikost = 0;
}

void vloz_na_zacatek(Seznam& s, T co)
{
	s.hlava = new Prvek{ co, s.hlava };
	s.velikost++;
}

void vloz_na_konec(Seznam& s, T co)
{
	s.zarazka->data = co;
	s.zarazka->dalsi = new Prvek{ NULA, nullptr };
	s.zarazka = s.zarazka->dalsi;
	s.velikost++;
}

void odstran_prvni(Seznam& s)
{
	auto pom = s.hlava;
	s.hlava = s.hlava->dalsi;
	delete pom;
	s.velikost--;
}

bool prazdny(Seznam& s)
{
	//return s.hlava == s.zarazka;
	return !s.velikost;
}
size_t velikost_seznamu(Seznam& s)
{
	return s.velikost;
}

void vyprazdni(Seznam& s)
{
	while (!prazdny(s))
	{
		odstran_prvni(s);
	}
}

void zrus(Seznam& s)
{
	vyprazdni(s);
	delete s.hlava;
}