#include <stdlib.h>
#include <assert.h>
#include <iostream>

using namespace std;

int Faktorial(int n)
{
	assert(n>=0);
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