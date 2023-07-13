// Soubor 08-03.CPP
// Eratosthenovo sito

#include <iomanip>
#include <iostream>
#include <conio.h>
using namespace std;
const int N = 300;  									// Horní mez prvoèísel
const int M = 10;   									// Poèet sloupcù výpisu

void Sito(int *pole, int n)				// Vyhledávání prvoèísel
{
	// Do pole uložíme celá èísla
	for(int *u = pole, i = 0; u < pole+n; u++) 
		*u = i++;
		// Vlastní síto
	*(pole+1) = 0;  								// Jednièka není prvoèíslo
	for(u = pole; u < pole+n; u++)
	{
		if(*u) 											// èíslo, které jsme neodstranili 
		{														// je prvoèíslo(!= 0)
			int dist = u - pole; 				// Krok procházení
			for(int *v = u+dist; v < pole+n; v += dist) *v = 0;
		}
	}
}

void Vypis(int *pole, int n) 			// Výpis prvoèísel
{
	int i = 1;
	//clrscr();
	cout << "Výpis prvoèísel od 2 do " << N << endl;
	for(int* u = pole; u < pole+n; u++)
	if(*u)
	{	// Nastavíme šíøku výstupního pole na 5 znakù
		cout << setw(5) << *u;
		if (i++ % M == 0) cout << endl;
	}
}

int main()
{
	int A[N];							// Pole, ve kterém budeme hledat prvoèísla
	Sito(A, N);						// Vlastní výpoèet
	Vypis(A, N);					// Výstup výsledkù
	return 0;
}
