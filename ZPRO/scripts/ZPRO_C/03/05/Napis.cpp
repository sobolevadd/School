// P�t� program: n�pis objektov�
// soubor s definic� metod

#include <cstring>
#include <iostream>
#include "napis.h"
using namespace std;

napis::napis(char zadani[])
{
   nastav(zadani);
}

void napis::nastav(char zadani[])
{
  strcpy(text, zadani);
}


void napis::vypis()
{
  cout << text << endl;
}

