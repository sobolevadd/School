#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

int Faktorial(int n)
{
	if(n < 0) throw invalid_argument("záporný argument faktoriálu");
	int vysledek = 1;
	while(n)
	{
		vysledek *= n--;
	}
	return n;
}

int main()
{
	system("CHCP 1250 > NUL");
	int n = 7;
	cout << "Faktoriál " << n << " je " << Faktorial(n) << endl;
	n = -7;
	cout << "Faktoriál " << n << " je " << Faktorial(n) << endl;
}
