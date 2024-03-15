// Soubor 17-05.c
// Strukturovane vyjimky - Koncovka a handler

#include <windows.h>
#include <stdio.h>

int main() 
{
	__try
	{
		printf("Vn�j�� blok s handlerem\n");
		__try {
			printf("Vnit�n� blok s koncovkou\n");
			RaiseException(0,0,0,0);
			printf("Jsme za v�jimkou\n");
		}
		__finally 
		{
			printf("Koncovka vnit�n�ho bloku\n");
		}
	}
	__except(printf("Jsme ve filtru\n"), EXCEPTION_EXECUTE_HANDLER)
	{
		printf("Jsme v handleru vn�j��ho bloku\n");
	}
	printf("�mytec");
	return 0;
}
