#include "seznam.h"

void vytvor(seznam& s)
{
	s.hlava = s.zarazka = new prvek{ NULA, nullptr };
	s.velikost = 0;
}

void vloz_na_zacatek(seznam& s, T co)
{
	s.hlava = new prvek{ co, s.hlava };
	s.velikost++;
}

void vloz_na_konec(seznam& s, T co)
{
	s.zarazka->data = co;
	s.zarazka->dalsi = new prvek{ co, nullptr };
	s.zarazka = s.zarazka->dalsi;
	s.velikost++;
}

void odstran_prvni(seznam& s)
{
	auto pom = s.hlava;
	s.hlava = s.hlava->dalsi;
	delete pom;
	s.velikost--;
}

