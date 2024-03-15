// Soubor 20-00K.cpp
// Pouziti funkce vfprintf()
// stridave psani do dvou souboru

#include <stdio.h>
#include <stdarg.h>
FILE *F[2] = {				/*pole dvou ukazatelù na FILE */
	fopen("data1.dta", "w"),
	fopen("data2.dta", "w"),
}; 

FILE *G = fopen("file.h", "w");
	
void Tisk(const char *f,...)
{
	static int i = 0; 	/* Urèuje, do kterého proudu se zapisuje */
	va_list ap;
	va_start(ap, f);
	vfprintf(F[i++], f, ap);
	i%=2;
}

int main()
{
	for(int i = 0; i < 10; i++) Tisk("%d", i);

	for(int i = 0; i < 2; i++) fclose(F[i]);
}