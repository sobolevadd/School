// Soubor 17-05A.c
// Handler pro neosetrene vyjimky

#include <windows.h>
#include <stdio.h>
LONG WINAPI 					// Dnes znamená totéž co long __stdcall
Filtr(PEXCEPTION_POINTERS Ei)	/* Nový filtr */
{
	printf("Pozor, neošetøená výjimka!\n");
	return EXCEPTION_EXECUTE_HANDLER;
}

void DelejToCoMas(){
	RaiseException(0,0,0,0);
}

int main()
{	
	SetUnhandledExceptionFilter(&Filtr);
	__try {									/* Vlastní program */
		DelejToCoMas();
	}												/* Handler pro neošetøené výjimky */
	__except(UnhandledExceptionFilter(GetExceptionInformation()))
	{
		printf("Zachycena neošetøená výjimka\n");
	}
		return 0;
}
