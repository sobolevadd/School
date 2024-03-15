// Soubor 08-0C.CPP
// Znakove retezce - pouziti adresove aritmetiky

#include <iostream>
using namespace std;

char *c = "ahoj";

char *d = c;  // Oba ukazatele ukazuji na tyz retezec

void kopiruj(char c[], char d[]);

int main()
{
 d[2] = 'j';
 cout << c << endl;  // vypise "ahjj"
 char t[10]; // prazdne pole znaku;
 kopiruj(t, c);
}

// funkce pro kopirovani znakoveho retezce
void kopiruj(char a[], char b[]) // z b do a
{
 while(*a++ = *b++);  // cela prace je v podmince cyklu
}