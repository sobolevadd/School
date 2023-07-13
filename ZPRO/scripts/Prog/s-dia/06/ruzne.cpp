#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <climits>
#include <limits>
#include <cstdint>
#include <array>
#include <iomanip>

using namespace std;



int d�lka(const char* txt)
{
	const char* pom = txt;
	while (*pom)
	{
		pom++;
	}
	return pom - txt;
}


void tabelace(double po��tek, double konec, int kolik, double(*fce)(double))
{
	double h = (konec - po��tek) / kolik;
	cout << setiosflags(ios::showpoint);
	cout << "Tabulka funkce F od " << po��tek << " do " << konec << endl;
	cout << "x" << setw(13) << "f(x)" << endl;
	cout << "------------------" << endl;
	double x = po��tek;
	for (int i = 0; i <= kolik; i++)
	{
		cout << setprecision(2) << x << setw(14)
			<< setprecision(6) << fce(x) << endl;
		x += h;
	}
}

template<typename T>
void proho�(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

int main()
{
	int a = 8, b = 6;
	proho�(a, b);
	cout << a << endl;
	tabelace(0, 1, 10, sin);
}																