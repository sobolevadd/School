// Program Treti2
// V�PO�ET FAKTORI�LU, P��KAZ IF
// U VSTUPU OV��UJEME, ZDA JE ZADAN� HODNOTA NEZ�PORN�

#include <iostream>
using namespace std;

int zadano,  
    vysledek = 1, 
    i = 1;       


int main()
{
  cout << "Zadej ��slo: ";
  cin >> zadano;
  if(zadano >= 0)  
  {
    while(i < zadano+1) 
    {
      vysledek = vysledek * i++;
    }
    cout << "Faktori�l " << zadano << " je " << vysledek << endl;
  } else {
    cout << "Z�porn� ��sla nejsou dovolena" << endl;
  }
}