// T�et� program
// OP�T FAKTORI�L, STRU�N�J�� Z�PIS 
// POMOC� OPER�TOR� *= A ++

#include <iostream>
using namespace std;
 
  int zadano,           // z �eho budeme faktori�l po��tat
      vysledek = 1,     // V t�to prom�nn� bude v�sledek
      i = 1;            // Pomocn� prom�nn�

int main()
{
  // Z�sk�n� vstupu od u�ivatele
  cout << "Zadej cislo: ";
  cin >> zadano;
  
  // V�po�et faktori�lu
  while (i < zadano+1)  // Dokud je i < zadano+1, opakuj tyto kroky:}
  {
    vysledek *= i;
    i++;        // Krok 4 a 5 algoritmu
    
  }

  // V�pis vypo�ten� hodnoty faktori�lu
  cout << "Faktorial " << zadano << " je " << vysledek;
}