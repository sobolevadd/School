#include <iostream>
#include <stdlib.h>

using namespace std;


void Chyba(int n)
{
	cout << "Nastala neo�ek�van� okolnost: ";
	switch (n)
	{
	case 0:
		cout << "D�len� nulou";
		break;
	case 1:
		cout << "Z�porn� argument faktori�lu";
		break;
	case 2:
		cout << "P�ete�en�";
		break;
	default:
		cout << "Jin� chyba";
		break;
	}
	cout << endl;
	exit(n+1);
}

const int pocet = 3;
const char zprava[pocet+1][30] = {"D�len� nulou", "Z�porn� argument faktori�lu", "P�ete�en�", "Jin� chyba"};

void Chyba1(int n)
{
	if ((n < 1) || (n > pocet))
		n = pocet + 1;
	cout << "Nastala neo�ek�van� okolnost: " << zprava[n] << endl;
	exit(n+1);
}



int main()
{
	system("CHCP 1250 > NUL");
	Chyba1(1);
}