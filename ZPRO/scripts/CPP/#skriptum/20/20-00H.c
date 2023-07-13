// Soubor 20-00H.c
// Pouziti maker pro vstup a vystup
// rozsirenych typu
// POUZE C99

<inttypes.h>.
#include <inttypes.h>
#include <stdio.h>
int main(void)
{
	uintmax_t i = UINTMAX_MAX; // Tento typ je vždy k dispozici
	printf("Nejvìtší celoèíselná hodnota je %020" PRIxMAX "\n", i);
	return 0;
}
