// Soubor 17-05A.c
// Handler pro neosetrene vyjimky

#include <windows.h>
#include <stdio.h>
LONG WINAPI 					// Dnes znamen� tot� co long __stdcall
Filtr(PEXCEPTION_POINTERS Ei)	/* Nov� filtr */
{
	printf("Pozor, neo�et�en� v�jimka!\n");
	return EXCEPTION_EXECUTE_HANDLER;
}

void DelejToCoMas(){
	RaiseException(0,0,0,0);
}

int main()
{	
	SetUnhandledExceptionFilter(&Filtr);
	__try {									/* Vlastn� program */
		DelejToCoMas();
	}												/* Handler pro neo�et�en� v�jimky */
	__except(UnhandledExceptionFilter(GetExceptionInformation()))
	{
		printf("Zachycena neo�et�en� v�jimka\n");
	}
		return 0;
}
