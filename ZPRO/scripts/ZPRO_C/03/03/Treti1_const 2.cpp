// Program Treti
// V�PO�ET FAKTORI�LU, P��KAZ IF
// U VSTUPU OV��UJEME, ZDA JE ZADAN� HODNOTA NEZ�PORN� 
// A MEN�� NE� 13

#include <iostream>
using namespace std;

int zadano,  
    vysledek = 1, 
    i = 1;       

const int DolniMez = 0, HorniMez = 12;

int main()
{
  cout << "Zadej ��slo: ";
  cin >> zadano;
  if((zadano >= DolniMez) && (zadano <= HorniMez))  
  {
    while(i < zadano+1) 
    {
      vysledek = vysledek * i++; // vysledek = vysledek * i; i++; // vysledek = vysledek * (i+1);
    }
    cout << "Faktori�l " << zadano << " je " << vysledek << endl;
  } else {
    cout << "Zadan� ��slo le�� mimo dovolen� rozsah" << endl;
  }
}