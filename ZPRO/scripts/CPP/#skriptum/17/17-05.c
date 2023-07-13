// Soubor 17-05.c
// Strukturovane vyjimky - Koncovka a handler

#include <windows.h>
#include <stdio.h>

int main() 
{
	__try
	{
		printf("Vnìjší blok s handlerem\n");
		__try {
			printf("Vnitøní blok s koncovkou\n");
			RaiseException(0,0,0,0);
			printf("Jsme za výjimkou\n");
		}
		__finally 
		{
			printf("Koncovka vnitøního bloku\n");
		}
	}
	__except(printf("Jsme ve filtru\n"), EXCEPTION_EXECUTE_HANDLER)
	{
		printf("Jsme v handleru vnìjšího bloku\n");
	}
	printf("Šmytec");
	return 0;
}
