// Soubor 20-00G.cpp
// Pouziti funkce fprintf()

#include <stdio.h>
int main()
{
	int i;							// Jsme v C, deklarace musí být pøed pøíkazy
	FILE *F = fopen("data.dta", "w");			// Otevøeme soubor
	if(!F) return 1;						// Pokud se to nepovede, konec
	for(i = 1; i <= 10; i++)
 		fprintf(F, "%d\n", i);		// Vypíšeme èísla
	fclose(F);									// Uzavøene soubor
	return 0;
}
