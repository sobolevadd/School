// Soubor 20-00J.cpp
// Pouziti sscanf() pro zpracovani parametru
// funkce main()

#include <stdio.h>
void main(int argc, char* argv[])
{ 
	long i;
	char c[100];
	if (argc > 1) sscanf(argv[1],"%li", &i);
	sprintf(c, "Druhá mocnina parametru je %li", i*i);
	printf("%s", c);
}
