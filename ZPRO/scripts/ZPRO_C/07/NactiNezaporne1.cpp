#include <iostream>
#include <stdlib.h>

using namespace std;


int NactiNezaporneCislo1()
{
	int i;
	for( ; ; )
	{
		cout << "Zadej nezáporné celé èíslo: ";
		cin >> i;
		if(i >= 0) return i;
		cout << "To není nezáporné celé èíslo." << endl;
	}
}


int faktorial(int n)
{
	int vysledek = 1;
	for(int i = 2; i <= n; i++)
		vysledek *= i;
	return vysledek;
}

int main()
{
	char txt[10];
	Strcpy(txt, "Ahoj");
	system("CHCP 1250 > NUL");
	int n = NactiNezaporneCislo1();
	cout << "Jeho faktoriál je " << faktorial(n) << endl;
}