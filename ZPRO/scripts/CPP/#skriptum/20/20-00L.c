// Soubor 20-00L.c
// Vystup se sirokymi znaky
// Pouziti maker pro vystup rozsirenych typ� (Jen C99)


#include <inttypes.h>		// Jen C99
#include <wchar.h>

int main(void)
{
	uintmax_t i = UINTMAX_MAX; 
	wprintf(L"Nejv�t�� hodnota je %020"PRIxMAX "\n", i);
	return 0;
}
