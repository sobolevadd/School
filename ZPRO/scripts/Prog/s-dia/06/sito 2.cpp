#include <iomanip>
#include <iostream>
#include <locale>
#include <conio.h>
#include <cstdlib>
using namespace std;

const int M = 10;                        // Po�et sloupc� v�pisu

int n;                                   // Horn� mez prvo��sel
int *pole;

void s�to()                              // Vyhled�v�n� prvo��sel
{
    // Do pole ulo��me cel� ��sla
    for (int i = 0, *u = pole; u < pole + n; u++)
    {
        *u = i++;
    }
    // Vlastn� s�to
    *(pole + 1) = 0;                     // Jedni�ka nen� prvo��slo
    for (int *u = pole; u < pole + n; u++)
    {
        if (*u)                          // ��slo, kter� jsme neodstranili
        {                                // je prvo��slo (!= 0)
            int dist = u - pole;         // Krok proch�zen�
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

void v�pis()                             // V�pis prvo��sel
{
    int i = 1;
    clrscr();
    wcout << L"V�pis prvo��sel od 2 do " << n << endl;
    for (int* u = pole; u < pole + n; u++)
    {
        if (*u)                          // Nastav�me ���ku v�stupn�ho
        {                                // pole na 5 znak�
    		cout << setw(5) << *u;
            if (i++ % M == 0) cout << endl;
        }
    }
    cout << endl;
}

void p��prava()
{
    wcout.imbue(locale("Czech_Czech Republic.852"));
    wcout << L"Zadej horn� mez vypisovan�ch prvo��sel: ";
    cin >> n;
    if (n < 0) n = 300;
    pole = new int[n];
}

int main()
{
    p��prava();
    s�to();                        // Vlastn� v�po�et
    v�pis();                       // V�stup v�sledk�
    return 0;
}