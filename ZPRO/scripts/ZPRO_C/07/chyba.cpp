#include <iostream>
#include <stdlib.h>

using namespace std;


void Chyba(int n)
{
	cout << "Nastala neoèekávaná okolnost: ";
	switch (n)
	{
	case 0:
		cout << "Dìlení nulou";
		break;
	case 1:
		cout << "Záporný argument faktoriálu";
		break;
	case 2:
		cout << "Pøeteèení";
		break;
	default:
		cout << "Jiná chyba";
		break;
	}
	cout << endl;
	exit(n+1);
}

const int pocet = 3;
const char zprava[pocet+1][30] = {"Dìlení nulou", "Záporný argument faktoriálu", "Pøeteèení", "Jiná chyba"};

void Chyba1(int n)
{
	if ((n < 1) || (n > pocet))
		n = pocet + 1;
	cout << "Nastala neoèekávaná okolnost: " << zprava[n] << endl;
	exit(n+1);
}



int main()
{
	system("CHCP 1250 > NUL");
	Chyba1(1);
}