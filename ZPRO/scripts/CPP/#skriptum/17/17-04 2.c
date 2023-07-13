/* Soubor 17-04.c
 * Uvodni priklad na strukturovane vyjimky
 * Program skonci chybou, protoze pro i == 4 
 * vznikne vyjimka, kterou handler odmitne osetrit
 * a jiny tam neni
 */

#include <windows.h>
#include <stdio.h>
#define VYJIMKA_0 0 	/* Definujeme chybov� k�dy */
#define VYJIMKA_1 1
#define VYJIMKA_2 2
#define VYJIMKA_3 3
	
int Filtr(EXCEPTION_POINTERS *ep) 			/* Filtrovac� funkce */
{ 
	if(ep->ExceptionRecord->ExceptionFlags
												== EXCEPTION_NONCONTINUABLE)
		return EXCEPTION_EXECUTE_HANDLER;
 	else switch (ep->ExceptionRecord->ExceptionCode)
 	{
		case VYJIMKA_0: 					/* pou�ijeme k�d chyby */
 			return EXCEPTION_CONTINUE_EXECUTION;
 		case VYJIMKA_1:
 		case VYJIMKA_2:
 			return EXCEPTION_EXECUTE_HANDLER;;
 		case VYJIMKA_3:
 		default:
 			return EXCEPTION_CONTINUE_SEARCH;
 	}
}
	
int main()
{ 
	int i;
	for(i = 0; i < 5; i++)
	__try {
		printf("Je tu V�JIMKA_%i\n", i);
 		RaiseException(i, 0, 0, 0); 									/* ! */
 		printf("Jsme za v�jimkou\n");
	}
	__except(Filtr(GetExceptionInformation())) {
		printf("O�et�ujeme v�jimku\n");
	}
	return 0;
}
