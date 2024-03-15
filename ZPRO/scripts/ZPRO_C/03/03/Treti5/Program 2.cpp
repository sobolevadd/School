// program Treti4
// oP�T V�PO�ET FAKTORI�LU
// JAKO SAMOSTATN� FUNKCE,
// FUNKCE fakt()  JE V SAMOSTATN�M SOUBORU
// DEFLARACE FINKCE fakt() a PROM�NN� zadano
// JSOU V HLAVI�KOV�M SOUBORU

#include <iostream>
#include "Funkce.h"

using namespace std;
const int DolniMez = 0, HorniMez = 12;

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
