// Soubor 13-0A.CPP
// pouziti makra assert()
// Ve funkci fakt() overujeme, zda je n >=0
// POZOR: assert() JE LADIDI ZALEZITOST,
// takze takoveto pouziti ma smysl jen v pripade, ze 
// vime, ze je-li program v poradku,
// nemuze volat fakt() se zapornym parametrem.
// Jinak je treba pouzit nechanizmus vyjimek
// (Ta¨kze vlastne tento progtram ukazuje 
// NEVHODNE pouziti makra assert())

#include <iostream>
#include <cassert>
using namespace std;

unsigned long fakt(int n)
{
  assert(n>=0);					// Overujeme, zda je n >=0
  int s = 1;
  while(n > 1) s *= n--; 
  return s;    
}

int main()
{
 int i = 0;  
 cout << "Zadej i: ";
 cin >> i;
 cout << "faktorial i je " << fakt(i) << endl;
 return 0;
}

