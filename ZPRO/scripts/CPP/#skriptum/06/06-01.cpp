// Soubor 06-01.CPP
// Blokova struktura programu = zastineni promennych
// ve vnorenem bloku

#include <iostream>
using namespace std;
int main()
{
	int j=99; 	// j je v lok�ln� bloku funkce main()
	{	
	// za��tek vno�en�ho bloku
		int i=1, j=9;		// deklarace lok�ln�ch prom�nn�ch
		while(i<4) j*=i++;	// pou��v�me lok�ln� prom�nnou
		cout << j << endl;	// vyp�e 54
	}
	cout << j << endl;		// vyp�e 99
	return 0;
}
