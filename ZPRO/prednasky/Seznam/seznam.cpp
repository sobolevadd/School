#include <iostream>
#include <utility>

#include "seznam.h"
using namespace std;

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

iterator_seznamu najdi(Seznam& s, T co)
{
	s.zarazka->data = co;
	Prvek* pom = s.hlava;
	while (pom->data != co)
	{
		pom = pom->dalsi;
	}
	return iterator_seznamu{ pom, &s };
}

void vloz_za(Seznam& s, T co, Prvek* za_ktery)
{
	za_ktery->dalsi = new Prvek{ co, za_ktery->dalsi };
	s.velikost++;
}

void vypis(Seznam& s)
{
	/*for (Prvek* pom = s.hlava; pom != s.zarazka; pom = pom->dalsi)
	{
		cout << pom->data << ", ";
	}
	cout << endl;*/
	for (iterator_seznamu it = pocatek(&s); !rovna_se(it, konec(&s)); prejdi_na_dalsi(it))
	{
		cout << vrat_hodnotu(it) << ", ";
	}
	cout << endl;
}

void odstran_za(Seznam& s, Prvek* za_kterym)
{
	auto odstranovany = za_kterym->dalsi;
	if (odstranovany == s.zarazka) return;
	za_kterym->dalsi = odstranovany->dalsi;
	delete odstranovany;
	s.velikost--;
}

void odstran(Seznam& s, Prvek* ktery)
{
	if (ktery->dalsi == s.zarazka) //n Je-li odstra�ov�n posledn� prvek
	{
		s.zarazka = ktery;
		delete ktery->dalsi;
		ktery->dalsi = nullptr;
		s.velikost--;
	}
	else
	{
		ktery->data = ktery->dalsi->data;
		odstran_za(s, ktery);
	}
}

Prvek* najdi_nejmensi(Seznam& s)
{
	Prvek* nejmensi = s.hlava;
	
	Prvek* pom = s.hlava;
	while (pom != s.zarazka)
	{
		if (pom->data < nejmensi->data)
		{
			nejmensi = pom;
		}
		pom = pom->dalsi;
	}
	return nejmensi;
}

void serad(Seznam& s)
{
	Seznam pomocny;
	vytvor_seznam(pomocny);
	while (!prazdny(s))
	{
		Prvek* nejmensi = najdi_nejmensi(s);
		vloz_na_konec(pomocny, nejmensi->data);
		odstran(s, nejmensi);
	}
	swap(s.hlava, pomocny.hlava);
	swap(s.zarazka, pomocny.zarazka);
	swap(s.velikost, pomocny.velikost);
	zrus(pomocny);	
}

iterator_seznamu vytvor_iterator(Seznam* s, Prvek* prvek)
{
	return iterator_seznamu{prvek, s};
}

void prejdi_na_dalsi(iterator_seznamu& i)
{
	if (i.aktualni == i.s->zarazka)
	{
		return;
	}
	i.aktualni = i.aktualni->dalsi;
}

iterator_seznamu pocatek(Seznam* s)
{
	return iterator_seznamu{s->hlava, s};
}

iterator_seznamu konec(Seznam* s)
{
	return iterator_seznamu{s->zarazka, s};
}

T vrat_hodnotu(iterator_seznamu it)
{
	return it.aktualni->data;
}

void nastav_hodnotu(iterator_seznamu it, T co)
{
	it.aktualni->data = co;
}

bool rovna_se(iterator_seznamu it1, iterator_seznamu it2)
{
	return it1.aktualni == it2.aktualni;
}


