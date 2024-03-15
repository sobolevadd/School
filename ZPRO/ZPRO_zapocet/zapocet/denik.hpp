#ifndef __denik_HPP__
#define __denik_HPP__
#include "prvek.hpp"
#include <iostream>

struct denik;

denik *vytvoritDenik();
bool nacistZeSouboru (denik *d, string soubor);
bool zapsatDoSouboru (denik *d, string soubor);
void pridatPrvek (denik *d, mojeData data);
void smazatPrvky (denik *d);
void smazatDenik (denik *&d);
bool jePrazdny (denik *d);
void vytiskniDenik (denik *d);
bool smazatAutora (denik *d, string autor);
bool smazatTitul (denik *d, string titul);
void najitAutora (denik *d, string autor);
void najitTitul (denik *d, string titul);
//bool vymazat(denik *d, mojeData data);



#endif