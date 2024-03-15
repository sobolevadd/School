// Soubor 01-09\Napis.cpp
// Soubor s definici metod
#include <iostream>
#include <cstring>

#include "Napis.h"
using namespace std;

// Konstruktor bez parametru
Napis::Napis()
{
 text[0] = '\0'; // ulozi do prvniho prvku znak '\0'
		 // jt. prazdny retezec
}

// Konstruktor s jednim parametrem typu pole znaku
// (ve skutecnosti se predava ukazatel, mohli bychom psat Napis(char* t)
Napis::Napis(char t[])
{
  if(t)               // neni-li to ukazatel nikam (0)
    {
     strcpy(text, t); // prekopiruj retezec do pole text
    }                // pomoci standardni funkce strcpy (hlav. soubor string.h)
}

void Napis::Vypis()
{
  cout << text << endl;
}

Napis::~Napis()
{
  cout << "zanikla instance tridy napis" << endl;
}

