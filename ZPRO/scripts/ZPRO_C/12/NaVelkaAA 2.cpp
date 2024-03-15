#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int delka = 100;

const char mala[]  = "a��bc�d�e��fghi�jkl�mn�o��pqr��s�t�u��vwxy�z�";
const char velka[] = "A��BC�D�E��FGHI�JKLżMN�O��PQR��S�T�U��VWXY�Z�";


char * NaVelka(char * vstup)
{
	for(int i = 0; i < strlen(vstup); i++)
	{
		const char *p = strchr(mala, vstup[i]);
		if(p)
			vstup[i] = velka[p - mala];
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