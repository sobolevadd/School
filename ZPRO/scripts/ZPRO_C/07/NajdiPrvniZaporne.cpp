#include <iostream>
#include <stdlib.h>

using namespace std;


const int m = 2, n = 3;

int NajdiPrvniZaporne(int X[][n])
{
    bool nalezeno = false;                            // Zat�m nic nebylo nalezeno
	int vysledek = 1;           
	for(int i = 0; i < m; i++)                    // Proch�z�me jednotliv� ��dky
	{
		for(int j = 0; j < n; j++)            // Poch�z�me jednotliv� prvky v ��dku
		{
			if(X[i][j] < 0)               // Kdy� najdeme z�porn� ��slo,
			{
				nalezeno = true;      // nastav�me p��znak a v�sledek
				vysledek = X[i][j];
				break;                // a opust�me vnit�n� cyklus
			}              // Ve vn�j��m cyklu zkontrolujeme, zda jsme se
		}                      // sem dostali po nalezen� v�sledku, a pokud ano,
		if(nalezeno) break;                   // opust�me i vn�j�� cyklus a skon��me
	}
	return vysledek;
}

int NajdiPrvniZaporne1(int(* X)[n])
{
	int vysledek = 1;           
	for(int i = 0; i < m; i++)                  // Proch�z�me jednotliv� ��dky
	{
		for(int j = 0; j < n; j++)          // Poch�z�me jednotliv� prvky v ��dku
		{
			if(X[i][j] < 0)             // Kdy� najdeme z�porn� ��slo,
			{
				vysledek = X[i][j]; // nastav�me v�sledek
				goto Konec;         // a opust�me vnit�n� cyklus
			}              
		}              
	}
	Konec:
	return vysledek;
}




int main()
{
	system("CHCP 1250 > NUL");
	int M[m][n] = {{1,2,3}, {4,-5,6}};
	cout << "Prvn� z�porn� je " << NajdiPrvniZaporne(M) << endl; 
	cout << "Prvn� z�porn� je " << NajdiPrvniZaporne1(M) << endl;
}