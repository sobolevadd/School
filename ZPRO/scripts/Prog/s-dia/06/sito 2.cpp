#include <iomanip>
#include <iostream>
#include <locale>
#include <conio.h>
#include <cstdlib>
using namespace std;

const int M = 10;                        // Poèet sloupcù výpisu

int n;                                   // Horní mez prvoèísel
int *pole;

void síto()                              // Vyhledávání prvoèísel
{
    // Do pole uložíme celá èísla
    for (int i = 0, *u = pole; u < pole + n; u++)
    {
        *u = i++;
    }
    // Vlastní síto
    *(pole + 1) = 0;                     // Jednièka není prvoèíslo
    for (int *u = pole; u < pole + n; u++)
    {
        if (*u)                          // Èíslo, které jsme neodstranili
        {                                // je prvoèíslo (!= 0)
            int dist = u - pole;         // Krok procházení
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

void výpis()                             // Výpis prvoèísel
{
    int i = 1;
    clrscr();
    wcout << L"Výpis prvoèísel od 2 do " << n << endl;
    for (int* u = pole; u < pole + n; u++)
    {
        if (*u)                          // Nastavíme šíøku výstupního
        {                                // pole na 5 znakù
    		cout << setw(5) << *u;
            if (i++ % M == 0) cout << endl;
        }
    }
    cout << endl;
}

void pøíprava()
{
    wcout.imbue(locale("Czech_Czech Republic.852"));
    wcout << L"Zadej horní mez vypisovaných prvoèísel: ";
    cin >> n;
    if (n < 0) n = 300;
    pole = new int[n];
}

int main()
{
    pøíprava();
    síto();                        // Vlastní výpoèet
    výpis();                       // Výstup výsledkù
    return 0;
}