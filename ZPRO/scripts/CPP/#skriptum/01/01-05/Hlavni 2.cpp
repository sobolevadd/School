// Soubor 01-05\Hlavni.cpp
// Hlavini program -- stale se pocita faktorial
// vklada hlavickovy soubor s deklaraci funkce fakt()

#include <iostream>
#include "fakt.h"
using namespace std;

int main()
{
 int i = 0;					// lokalni promenna
 cout << "Zadej i: ";
 cin >> i;
 cout << "faktorial i je " << fakt(i) << endl;
 return 0;
}

