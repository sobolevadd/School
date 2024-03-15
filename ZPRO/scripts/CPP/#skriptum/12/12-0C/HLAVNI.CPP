// Soubor Hlavni.cpp

/* Priklad na volani funkce napsane v C v programu v C++
	hlavickovy soubor fun.h obsahuje prototyp funkce F(), upraveny tak, aby
	jej bylo mozno pouzit jak v C tak i v C++

	Pro preklad a sopusteni tohoto programu je treba definovat projekt,
	slozeny ze souboru FUN.C a HLAVNI.CPP
*/

#include "fun.h"

int main()
{
 F();               // F je napsana v C (soubor FUN.C)
 return 0;
}