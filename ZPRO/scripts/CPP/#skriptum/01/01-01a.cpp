// Soubor 01-01a.cpp
// Prvni program v C++
// vylepseny: smaze si predem obrazovku,
// pozada o zadani hodnoty promenne a vytiskne jeji druhou mocninu
// Lze prelozit jen v Borland C++, jinak nutno odstranit radky s hvezdickou 
// v komentari

#include <iostream>
#include <conio.h>		// *
using namespace std;

int i; // globalni promenna

int main()
{
 clrscr();				// *
 cout << "Zadej i: ";
 cin >> i;
 cout << "druha mocnina je " << i*i << endl;
 return 0;
}

// funkce clrscr() maze obrazovku; informace o ni najde prekladac v
// souboru <conio.h> (neni soucasti standardu, najdeme ji jen v Borland C++

// cin je standardni vstupni datovy proud