// program Treti4
// oPÌT VÝPOÈET FAKTORIÁLU
// JAKO SAMOSTATNÉ FUNKCE,
// FUNKCE fakt()  JE V SAMOSTATNÉM SOUBORU

#include <iostream>
int fakt(int n);             // Informativní deklarace
extern int zadano;           // Informativní deklarace
const int DolniMez = 0, HorniMez = 12;

using namespace std;

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
