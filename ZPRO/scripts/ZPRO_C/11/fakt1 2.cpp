#include <iostream>
#include <stdlib.h>


using namespace std;

double faktorial(int n)
{
	double vysledek = 1.0;
	while(n > 1)
	{
		vysledek *= n--;
	}
	return vysledek;
}

double faktorial1(int &n)
{
	double vysledek = 1.0;
	while(n > 1)
	{
		vysledek *= n--;
	}
	return vysledek;
}

int main()
{
	system("CHCP 1250 > NUL");
	int i = 6;
	cout << "Po��te�n� hodnota i: " << i << endl;
	double x = faktorial(i);
	cout << "Faktori�l i je: " <<  x << endl;
	cout << "Hodnota i po vol�n� funkce faktorial: " << i << endl;
	x = faktorial1(i);
	cout << "Faktori�l i je: " <<  x << endl;
	cout << "Hodnota i po vol�n� funkce faktorial1: " << i << endl;
}