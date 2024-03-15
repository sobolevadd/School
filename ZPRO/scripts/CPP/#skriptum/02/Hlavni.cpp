// Soubor Hlavni.cpp
// Hlavni program - funkce main()

#include "cplx.h"
int main()
{
// nejprve se podivejme na pouziti implicitnich parametru
// pri volani funkce - zde konstruktoru:
  cplx a(1.1,1.2), b(2.1),c; // Znamena totez jako a(1.1,1.2), b(2.1,0), c(0,0)
  // tj. za vynechane parametry se dosazuji implicitni hodnoty

  // Nyni muzeme napsat
  c = -a;  // znamena totez jako c = a.operator-()
  // vola se tedy metoda operandu
  c = a+b; // znamena totez jako c - a.operator+(b).
  // Vola se tedy metoda leveho operandu, pravy se predava jako parametr
  cin >> c;
  cout << c << endl;
  // ...a dalsi si vyzkousejte sami
  return 0;
}

