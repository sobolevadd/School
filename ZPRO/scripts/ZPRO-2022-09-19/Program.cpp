#include <iostream>

using namespace std;

int main()
{
	double n;
	cout << "Zadej cel‚ Ÿ¡slo: ";
	cin >> n;
	double vysledek = 1;
	while (n > 1)
	{
		vysledek *=  n--;
	}
	cout << "Jeho faktori l je " << vysledek << endl;
}