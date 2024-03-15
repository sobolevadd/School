// Soubor 08-03.CPP
// Eratosthenovo sito

#include <iomanip>
#include <iostream>
#include <conio.h>
using namespace std;
const int N = 300;  									// Horn� mez prvo��sel
const int M = 10;   									// Po�et sloupc� v�pisu

void Sito(int *pole, int n)				// Vyhled�v�n� prvo��sel
{
	// Do pole ulo��me cel� ��sla
	for(int *u = pole, i = 0; u < pole+n; u++) 
		*u = i++;
		// Vlastn� s�to
	*(pole+1) = 0;  								// Jedni�ka nen� prvo��slo
	for(u = pole; u < pole+n; u++)
	{
		if(*u) 											// ��slo, kter� jsme neodstranili 
		{														// je prvo��slo(!= 0)
			int dist = u - pole; 				// Krok proch�zen�
			for(int *v = u+dist; v < pole+n; v += dist) *v = 0;
		}
	}
}

void Vypis(int *pole, int n) 			// V�pis prvo��sel
{
	int i = 1;
	//clrscr();
	cout << "V�pis prvo��sel od 2 do " << N << endl;
	for(int* u = pole; u < pole+n; u++)
	if(*u)
	{	// Nastav�me ���ku v�stupn�ho pole na 5 znak�
		cout << setw(5) << *u;
		if (i++ % M == 0) cout << endl;
	}
}

int main()
{
	int A[N];							// Pole, ve kter�m budeme hledat prvo��sla
	Sito(A, N);						// Vlastn� v�po�et
	Vypis(A, N);					// V�stup v�sledk�
	return 0;
}
