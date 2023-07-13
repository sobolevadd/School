// Soubor 01-03.cpp
// Druhy program v C++
// funkce pro vypocet faktorialu

#include <iostream>
using namespace std;

// deklarace funkce pro vypocet faktorialu
unsigned long fakt(int n)
{
  int s = 1;
  while(n > 1)
  {
   s *= n--; // znamená totéž co s = s*n; n = n-1;
  }
  return s;    // ukonci funkci a vrat
	       // jako vysledek hodnotu i;
}

int main()
{
 int i = 0;  // lokalni promenna
 cout << "Zadej i: ";
 cin >> i;
 cout << "faktorial i je " << fakt(i) << endl;
 return 0;
}

// Telo cyklu while znamena totez co
// while(n > 1)
//  {
//   s = s*n; 
//	 n--;	
//  }
//
// nebo
//
// Telo cyklu while znamena totez co
// while(n > 1)
//  {
//   s = s*n; 
//	 n = n-1;	
//  }