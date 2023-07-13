// program Treti2
// oPÌT VÝPOÈET FAKTORIÁLU, TENTOKRÁT
// JAKO SAMOSTATNÉ FUNKCE

#include <iostream>
using namespace std;

int zadano;                         // Obsahuje vstup od uživatele

const int DolniMez = 0, HorniMez = 12;

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

int main()                             
{                                      // Zaèátek vlastního programu
  cout << "Zadej èíslo: ";             // Získání vstupu od uživatele
  cin >> zadano;
  if((zadano >= DolniMez) && (zadano <= HorniMez))
  {                                    // Výpis výsledku
    cout << "Faktoriál " << zadano << " je " << fakt(zadano) << endl;
  }
  else
  {
    cout << "Zadané èíslo leží mimo dovolený rozsah" << endl;
  }  
}