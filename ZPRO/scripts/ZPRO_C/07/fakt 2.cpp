#include <iostream>
#include <stdlib.h>

using namespace std;


int NactiNezaporneCislo()
{
	int nacteno;
	do
	{
		cout << "Zadej nez�porn� ��slo: ";
		cin >> nacteno;
	} while (nacteno < 0);
	return nacteno;
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
	system("CHCP 1250 > NUL");
	int n = NactiNezaporneCislo();
	cout << "Jeho faktori�l je " << faktorial(n) << endl;
}