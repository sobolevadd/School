// Tøetí program
// VÝPOÈET FAKTORIÁLU -- PRVNÍ POKUS

#include <iostream>
using namespace std;
 
  int zadano,           // z èeho budeme faktoriál poèítat
      vysledek = 1,     // V této promìnné bude výsledek
      i = 1;            // Pomocná promìnná

int main()
  {
  // Získání vstupu od uživatele
  cout << "Zadej cislo: ";
  cin >> zadano;
  
  // Výpoèet faktoriálu
  while (i < zadano+1)  // Dokud je i < zadano+1, opakuj tyto kroky:}
  {
    vysledek = vysledek * i;         // Krok 4 algoritmu
    i = i + 1;                      // Krok 5 algoritmu
  }

  // Výpis vypoètené hodnoty faktoriálu
  cout << "Faktorial " << zadano << " je " << vysledek;
}