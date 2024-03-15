// Soubor 01-05\fakt.cpp
// Soubor s implementaci (definici)
// funkce pro vypocet faktorialu

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
