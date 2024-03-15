// program Treti3
// oP�T V�PO�ET FAKTORI�LU
// JAKO SAMOSTATN� FUNKCE,
// AV�AK JIN� PO�AD� DEKLARAC�

#include <iostream>
using namespace std;

const int DolniMez = 0, HorniMez = 12;

int fakt(int n);
extern int zadano;

int main()                             
{                                      // Za��tek vlastn�ho programu
  cout << "Zadej ��slo: ";             // Z�sk�n� vstupu od u�ivatele
  cin >> zadano;
  if((zadano >= DolniMez) && (zadano <= HorniMez))
  {                                    // V�pis v�sledku
    cout << "Faktori�l " << zadano << " je " << fakt(zadano) << endl;
  }
  else
  {
    cout << "Zadan� ��slo le�� mimo dovolen� rozsah" << endl;
  }  
}

int zadano;                         // Obsahuje vstup od u�ivatele

/* Funkce fakt vypo�te faktori�l cel�ho ��sla n.
 * n mus� b�t nez�porn� cel� ��slo
 * men�� ne� 13
 * Pro z�porn� n vrac� 1
 */

int fakt(int n)                   // Hlavi�ka funkce
{
  int vysledek = 1,                    // Deklarace lok�ln�ch prom�nn�ch
  i = 1;
  while(i < n+1) 
  {
    vysledek *= i++;
  }
  return vysledek;                     // Zde ur�ujeme, co je v�sledkem funkce
}    

