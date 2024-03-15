#include <iomanip>
#include <iostream>
#include <locale>
#include <conio.h>
#include <cstdlib>
using namespace std;

const int M = 10;                        // Pocet sloupcu vypisu

int n;                                   // Horni mez prvocisel
int *pole;

void sito()                              // Vyhledavani prvocisel
{
    // Do pole ulozime cela cisla
    for (int i = 0, *u = pole; u < pole + n; u++)
    {
        *u = i++;
    }
    // Vlastni sito
    *(pole + 1) = 0;                     // Jednicka neni prvocislo
    for (int *u = pole; u < pole + n; u++)
    {
        if (*u)                          // Cislo, ktere jsme neodstranili
        {                                // je prvocislo (!= 0)
            int dist = u - pole;         // Krok prochazeni
            for (int *v = u + dist; v < pole + n; v += dist)
            {
                *v = 0;
            }
        }
    }
}

void clrscr()
{
    system("CLS");
}

void vypis()                             // Vypis prvocisel
{
    int i = 1;
    clrscr();
    wcout << L"Vypis prvocisel od 2 do " << n << endl;
    for (int* u = pole; u < pole + n; u++)
    {
        if (*u)                          // Nastavime sirku vystupniho
        {                                // pole na 5 znaku
    		cout << setw(5) << *u;
            if (i++ % M == 0) cout << endl;
        }
    }
    cout << endl;
}

void priprava()
{
    wcout.imbue(locale("Czech_Czech Republic.852"));
    wcout << L"Zadej horni mez vypisovanych prvocisel: ";
    cin >> n;
    if (n < 0) n = 300;
    pole = new int[n];
}

int main()
{
    priprava();
    sito();                        // Vlastni vypocet
    vypis();                       // Vystup vysledku
    return 0;
}