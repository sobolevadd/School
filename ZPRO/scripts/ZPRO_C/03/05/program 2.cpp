// P�t� program: n�pis objektov�
// Hlavn� program

#include <cstring>
#include <iostream>
#include "napis.h"

using namespace std;


int main()
{
  napis pozdrav("Ahoj, lidi");
  pozdrav.vypis();
  pozdrav.nastav("Nazdar, vy tam");
  pozdrav.vypis();
}