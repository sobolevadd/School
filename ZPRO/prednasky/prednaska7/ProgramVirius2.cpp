#include "seznamVirius.h"
#include <iostream>

using namespace std;

int main()
{
	Seznam s1;
	vytvor(s1);
	vloz_na_zacatek(s1, 4);
	vloz_na_zacatek(s1, 5);
	vloz_na_konec(s1, 10);
	//odstran_prvni(s1);
	auto p = najdi(s1, 4);
	vloz_za(s1, 8, p);
	vypis(s1);
	p = najdi(s1, 4);
	// delete p; //!!!
	/*odstran(s1, p);
	p = najdi(s1,10);
	odstran(s1, p);
	vypis(s1);*/
	vloz_na_konec(s1, 1);
	p = najdi_nejmensi(s1);
	cout << p->data << endl;
}