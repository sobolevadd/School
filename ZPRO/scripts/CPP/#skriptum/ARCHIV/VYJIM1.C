// PROGRAM VYJIMKY.C
#include <excpt.h>
#include <stdio.h>
// Definice chybov˜ch k¢d–
#define CHYBA_0 0
#define CHYBA_1 1
#define CHYBA_2 2
#define CHYBA_3 3

// Filtrovac¡ funkce
int Filtr(EXCEPTION_POINTERS *ep)
{
 if(ep->ExceptionRecord->ExceptionFlags ==
         EXCEPTION_NONCONTINUABLE)
     return EXCEPTION_EXECUTE_HANDLER;
 else switch (ep->ExceptionRecord->ExceptionCode)
  {
  // Vyhodnocen¡ k¢du chyby
   case CHYBA_0:
   case CHYBA_2:
    return EXCEPTION_CONTINUE_EXECUTION;
   case CHYBA_1:
    return EXCEPTION_EXECUTE_HANDLER;;
   case CHYBA_3:
   default:
    return EXCEPTION_CONTINUE_SEARCH;
  }
}

void main()
{
 int i;
 for(i = 0; i < 5; i++)
 __try {
  printf("jedeme i = %i\n", i);
  RaiseException(i, 0, 0, 0);
  printf("n vrat po o¨et©en¡ v˜jimky\n");
}
 __except(Filtr(GetExceptionInformation())) {
  printf("o¨et©uji v˜jimku\n");
 }
}
