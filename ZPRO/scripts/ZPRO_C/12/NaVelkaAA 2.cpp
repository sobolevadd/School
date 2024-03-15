#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int delka = 100;

const char mala[]  = "aáäbcèdïeéìfghiíjklå¾mnòoóôpqràøsštuúùvwxyız";
const char velka[] = "AÁÄBCÈDÏEÉÌFGHIÍJKLÅ¼MNÒOÓÔPQRÀØSŠTUÚÙVWXYİZ";


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
	char vstup[delka];                                     // Pøeètenı øetìzec
	while(fgets(vstup, delka, stdin))
	{
		printf("%s", NaVelka(vstup));
	}
}