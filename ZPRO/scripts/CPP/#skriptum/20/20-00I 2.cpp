// Soubor 20-00I.cpp
// Neformatovane cteni a zapis

#include <stdio.h>
#define N 10
int main()
{
	int i, a[N];
	FILE *F = fopen("data.dta", "wb");
	for(i = 0; i < N; i++)
		fwrite(&i, sizeof(int), 1, F);	// Zapíšeme obsah i do souboru
	fclose(F);
	F = fopen("data.dta", "rb+");		// Otevøeme pro aktualizaci
	while(fread(&i, sizeof(int), 1, F))
	{
		i++;
		fseek(F, -(long)sizeof(int), SEEK_CUR);
		fwrite(&i, sizeof(int), 1, F);
		fseek(F, 0, SEEK_CUR);					// Nezbytné!!
	}
	rewind(F);							// Pøesun aktuální pozice na poèátek
	fread(a, sizeof(int), N, F);
	return 0;
}
