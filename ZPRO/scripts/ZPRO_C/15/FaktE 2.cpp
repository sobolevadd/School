#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

int Faktorial(int n)
{
	if(n < 0) throw invalid_argument("z�porn� argument faktori�lu");
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
	cout << "Faktori�l " << n << " je " << Faktorial(n) << endl;
	n = -7;
	cout << "Faktori�l " << n << " je " << Faktorial(n) << endl;
}
