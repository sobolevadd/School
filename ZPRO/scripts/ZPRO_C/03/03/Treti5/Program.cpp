// program Treti4
// oPÌT VÝPOÈET FAKTORIÁLU
// JAKO SAMOSTATNÉ FUNKCE,
// FUNKCE fakt()  JE V SAMOSTATNÉM SOUBORU
// DEFLARACE FINKCE fakt() a PROMÌNNÉ zadano
// JSOU V HLAVIÈKOVÉM SOUBORU

#include <iostream>
#include "Funkce.h"

using namespace std;
const int DolniMez = 0, HorniMez = 12;

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
