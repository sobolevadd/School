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

void vypis(const char * soubor)
{
	FILE * f = fopen(soubor, "wb");
	if(f)
	{
		for(int i = 5; i < 15; i++)
		{
			fwrite(&i, sizeof(int), 1, f);
		}
		fclose(f);
	}
	else
		Chyba(0);
}

void vypis2(const char * soubor)
{
	int pole[] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	FILE * f = fopen(soubor, "wb");
	if(f)
	{
		fwrite(pole, sizeof(int), sizeof(pole)/sizeof(int), f);
		fclose(f);
	}
	else
		Chyba(0);
}

void vypis3(const char * soubor, const int * pole, const int n)
{
	FILE * f = fopen(soubor, "wb");
	if(f)
	{
		fwrite(pole, sizeof(int), n, f);
		fclose(f);
	}
	else
		Chyba(0);
}

void cteni(const char * soubor)
{
	FILE * f = fopen(soubor, "rb");
	int i;
	if(f)
	{
		while(fread(&i, sizeof(int), 1, f))
		{
			cout << i << " ";
		}
		fclose(f);
		cout << endl;
	}
}

void aktualizace(const char * soubor)
{
    FILE * f = fopen(soubor, "r+b");
	int i;
	if(f)
	{
		while(fread(&i, sizeof(int), 1, f))  // Èteme záznamy do konce souboru
		{
			if(i % 2)                                // Je-li èíslo liché,
			{
				i = 2*i;                                    // zdvojnásobíme ho,
				fseek(f, -(long)sizeof(int), SEEK_CUR);     // o jeden int se vrátíme
				fwrite(&i, sizeof(int), 1, f);
				fseek(f, 0, SEEK_CUR);
			}
		}
		fclose(f);
	}
	else
		Chyba(0);
}

int main()
{
	system("CHCP 1250 > NUL");
	char * jmeno = "data.dta";
	cout << "Vytváøím soubor " << jmeno << endl;
	//vypis(jmeno);
	vypis2(jmeno);
	int pole[] = {101,102,104,106};
	//vypis3(jmeno, pole, sizeof(pole)/sizeof(int));
	cout << "Zpracovávám soubor " << jmeno << endl;
	cteni("data.dta");
	cout << "Aktualizuji soubor " << jmeno << endl;
	aktualizace(jmeno);
	cteni(jmeno);
}