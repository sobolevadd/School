// Soubor 01-04.cpp
// Prvni program v C++
// totez jako 01-03.cpp, ukazuje ale pouziti prototypu:
// definice funkce fakt() je umistena az za funkci main()
// a proto musime pred prvni pouziti zaradit informaci o ni - prototyp

#include <iostream>
using namespace std;

// Prototyp
unsigned long fakt(int n);

int main()
{
 int i = 0;					// lokalni promenna
 cout << "Zadej i: ";
 cin >> i;
 cout << "faktorial i je " << fakt(i) << endl;
 return 0;
}

// definice funkce pro vypocet faktorialu
unsigned long fakt(int n)
{
  unsigned long int s = 1;
  while(n > 1)
  {
   s *= n--;
  }
  return s;    // ukonci funkci a vrat
	       // jako vysledek hodnotu s;
}
