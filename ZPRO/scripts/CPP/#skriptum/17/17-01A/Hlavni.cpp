// Soubor 17-01A\Hlavni.CPP
// Priklad pouziti vyjimek vcetne deklarace vlastni 
// tridy vyjimek, navic transformace vyjimky 
// typu bad_alloc na jinou v metode seznam::vlozNaKonec()

#include "seznam.h"
#include <iostream>
using namespace std;
void Zpracuj(int i){ /* ... */ }
void VypisHlaseni(){ /* ... */ }
void Zaver(){ /* ... */ }
int main()
{
	try
	{
		seznam<int> s;
		for(int i = 1; i < 5; i++) s.vlozNaKonec(i);
		for(i = 1; i < 5; i++)
		{
			int j = s.vyjmiPrvni();
			Zpracuj(j);
		}
		VypisHlaseni();
	}
	catch(chyba_seznamu &c)
	{
		cout << c.co_je() << endl;
	}
	catch(...)
	{ 
		cout << "Pozor - neznámá výjimka!" << endl;
		terminate();							// Ukonèíme program
	}
	Zaver();
	// ...
	return 0;
}
