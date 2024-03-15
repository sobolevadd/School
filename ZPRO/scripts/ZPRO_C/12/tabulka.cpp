#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

void Chyba(unsigned n)
{
	const unsigned m = 2;
	char zpravy[m][30] = {"pøi otevírání souboru", "neznámého druhu"};
	if(n >= m) n = m - 1;
	cout << "Chyba " << zpravy[n] << endl;
}

void Tabulka(double (*f)(double), const char * jmeno, FILE* kam, double od, double po, int kolik)
{
	double krok = (po - od)/(kolik - 1);
	fprintf(kam, "Tabulka funkce %s\n", jmeno);
	fprintf(kam, "---------------------------------------\n");
	fprintf(kam, "   x                    %s(x)\n", jmeno);
	fprintf(kam, "---------------------------------------\n");
	for(int i = 0; i < kolik; i++)
	{
		double x = od + i*krok;
		fprintf(kam, "   %6.4f               %6.4f\n", x, f(x)); 
	}
}

int main()
{
	system("CHCP 1250 > NUL");
	Tabulka(sin, "sin", stdout, 0, 1, 11);

	FILE * f = fopen("data.txt", "w");
	Tabulka(sin, "sin", f, 0, 1, 11);
	fclose(f);
}