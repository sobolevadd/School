#include <iostream>
#include <stdlib.h>

using namespace std;

int FaktorialRekurzivne(int n)
{
	return n == 0 ? 1 : n * FaktorialRekurzivne(n-1); 
}

int main()
{
	system("CHCP 1250 > NUL");
	cout << "Zadej nez�po�n� ��slo: ";
	int n;
	cin >> n;
	cout << "Jeho faktori�l je " << FaktorialRekurzivne(n) << endl;
}