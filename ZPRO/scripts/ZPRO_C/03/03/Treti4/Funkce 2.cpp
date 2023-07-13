// SOUBOR OBSAHUJÍCÍ POUZE FUNKCI fakt()
// A PROMÌNNOU zadano


/* Funkce fakt vypoète faktoriál celého èísla n.
 * n musí být nezáporné celé èíslo
 * menší než 13
 * Pro záporná n vrací 1
 */

int fakt(int n)                   // Hlavièka funkce
{
  int vysledek = 1,                    // Deklarace lokálních promìnných
  i = 1;
  while(i < n+1) 
  {
    vysledek *= i++;
  }
  return vysledek;                     // Zde urèujeme, co je výsledkem funkce
}    

int zadano;                         // Obsahuje vstup od uživatele
