#ifndef __SEZNAM_H__
#define __SEZNAM_H__

//typedef int T;
using T = int;

const T NULA = 0;


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

struct iterator_seznamu
{
	Prvek* aktualni;
	Seznam* s;
};

void vytvor_seznam(Seznam& s);
void vloz_na_zacatek(Seznam& s, T co);
void vloz_na_konec(Seznam& s, T co);
void odstran_prvni(Seznam& s);
void vyprazdni(Seznam& s);
bool prazdny(Seznam& s);
size_t velikost_seznamu(Seznam& s);
void zrus(Seznam& s);
//-----------------
iterator_seznamu najdi(Seznam& s, T co);
void vloz_za(Seznam& s, T co, Prvek* za_ktery);
void vypis(Seznam& s);
void odstran_za(Seznam& s, Prvek* za_kterym);
void odstran(Seznam& s, Prvek* ktery);
Prvek* najdi_nejmensi(Seznam& s);
void serad(Seznam& s);
//-----------------
iterator_seznamu vytvor_iterator(Seznam* s, Prvek* prvek);
void  prejdi_na_dalsi(iterator_seznamu &i);
iterator_seznamu pocatek(Seznam* s);
iterator_seznamu konec(Seznam* s);
T vrat_hodnotu(iterator_seznamu it);
void nastav_hodnotu(iterator_seznamu it, T co);
bool rovna_se(iterator_seznamu it1, iterator_seznamu it2);

#endif // __SEZNAM_H__
