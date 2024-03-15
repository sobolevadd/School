// Soubor 01-09\Hlavni.cpp
// Totez co 01-08.CPP, ale rozdeleno do nekolika souboru
// Hlavni.cpp obsahuje funkci main() a pouziva tridu
// napis. Potrebuje znat pouze deklarøaci, 
// nikoli definici metod

#include "Napis.h"

// deklarace tridy Napis

Napis N1("Jak se vam to zamlouva?");  // Deklarace instance znamena volani konstruktoru

int main()
{
 N1.Vypis();	// Volani metody globalni instance
 Napis N2("Takhle to jde taky");
 N2.Vypis();
 return 0;
}

