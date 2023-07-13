// Pátý program: nápis objektovì
// soubor s definicí metod

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

