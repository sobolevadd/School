// Program Treti2
// VÝPOÈET FAKTORIÁLU, PØÍKAZ IF
// U VSTUPU OVÌØUJEME, ZDA JE ZADANÁ HODNOTA NEZÁPORNÁ

#include <iostream>
using namespace std;

int zadano,  
    vysledek = 1, 
    i = 1;       


int main()
{
  cout << "Zadej èíslo: ";
  cin >> zadano;
  if(zadano >= 0)  
  {
    while(i < zadano+1) 
    {
      vysledek = vysledek * i++;
    }
    cout << "Faktoriál " << zadano << " je " << vysledek << endl;
  } else {
    cout << "Záporná èísla nejsou dovolena" << endl;
  }
}