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
	cout << "Zadej nezápoèné èíslo: ";
	int n;
	cin >> n;
	cout << "Jeho faktoriál je " << FaktorialRekurzivne(n) << endl;
}