// KOMBINACE HANDLERU A KONCOVKY
#include <excpt.h>

int printf(char*,...);

void main()
{
 __try{
   printf("vn�j�� blok\n");
   __try {
   printf("vnit�n� blok\n");
   RaiseException(0,0,0,0);
   printf("za v�jimkou\n");
   }
   __finally {
    printf("koncovka vnit�n�ho bloku\n");
   }
 }
 __except(printf("vyhodnocen� filtru\n"),
   EXCEPTION_EXECUTE_HANDLER) {
   printf("handler vn�j��ho bloku\n");
 }
 printf("konec programu");
}
