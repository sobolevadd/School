#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int delka = 100;

const char mala[]  = "a��bc�d�e��fghi�jkl�mn�o��pqr��s�t�u��vwxy�z�";
const char velka[] = "A��BC�D�E��FGHI�JKLżMN�O��PQR��S�T�U��VWXY�Z�";

int Index(char co, const char* kde)
{
	int i;
	int delkaVstupu = strlen(kde);
	for(i = 0; i < delkaVstupu; i++)
	{
		if(co == kde[i]) break;
	}
	if(i < delkaVstupu) return i;
	else return -1;

}

char * NaVelka(char * vstup)
{
	for(int i = 0; i < strlen(vstup); i++)
	{
		int j = Index(vstup[i], mala);
		if(j >= 0)
			vstup[i] = velka[j];
	}
	return vstup;
}

int main()
{
	char vstup[delka];                                     // P�e�ten� �et�zec
	while(fgets(vstup, delka, stdin))
	{
		printf("%s", NaVelka(vstup));
	}
}