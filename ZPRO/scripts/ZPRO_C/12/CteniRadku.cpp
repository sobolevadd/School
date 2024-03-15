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

void ZpracujText(const char *jmeno)
{
	FILE *f = fopen(jmeno, "r");
	char radek[100];
	if(f)
	{
		while(fgets(radek, 99, f))
		{
			printf("%s", radek);
		}
		fclose(f);
	}
	else
	{
		Chyba(0);
	}
}


int main()
{
	system("CHCP 1250 > NUL");
	ZpracujText("data.txt");
}