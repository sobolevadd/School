#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

void Chyba(unsigned n)
{
	const unsigned m = 2;
	char zpravy[m][30] = {"pøi otevírání souboru", "neznámého druhu"};
	if(n >= m) n = m - 1;
	cout << "Chyba " << zpravy[n] << endl;
}

void ZpracujSoubor(const char * jmeno)
{
	FILE * f = fopen(jmeno, "r");
	if(f)
	{
		long x;
		while(fscanf(f, " %ld", &x) > 0)
		{
			printf("%ld\n", x);
		}
	}
	else
		Chyba(0);
}


int main()
{
	ZpracujSoubor("data.txt");
}