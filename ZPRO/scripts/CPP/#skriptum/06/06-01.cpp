// Soubor 06-01.CPP
// Blokova struktura programu = zastineni promennych
// ve vnorenem bloku

#include <iostream>
using namespace std;
int main()
{
	int j=99; 	// j je v lokální bloku funkce main()
	{	
	// zaèátek vnoøeného bloku
		int i=1, j=9;		// deklarace lokálních promìnných
		while(i<4) j*=i++;	// používáme lokální promìnnou
		cout << j << endl;	// vypíše 54
	}
	cout << j << endl;		// vypíše 99
	return 0;
}
