// Soubor 20-00G.cpp
// Pouziti funkce fprintf()

#include <stdio.h>
int main()
{
	int i;							// Jsme v C, deklarace mus� b�t p�ed p��kazy
	FILE *F = fopen("data.dta", "w");			// Otev�eme soubor
	if(!F) return 1;						// Pokud se to nepovede, konec
	for(i = 1; i <= 10; i++)
 		fprintf(F, "%d\n", i);		// Vyp�eme ��sla
	fclose(F);									// Uzav�ene soubor
	return 0;
}
