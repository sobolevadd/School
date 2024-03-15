#include <iostream>
#include <stdlib.h>

using namespace std;


const int m = 2, n = 3;

int NajdiPrvniZaporne(int X[][n])
{
    bool nalezeno = false;                            // Zatím nic nebylo nalezeno
	int vysledek = 1;           
	for(int i = 0; i < m; i++)                    // Procházíme jednotlivé øádky
	{
		for(int j = 0; j < n; j++)            // Pocházíme jednotlivé prvky v øádku
		{
			if(X[i][j] < 0)               // Když najdeme záporné èíslo,
			{
				nalezeno = true;      // nastavíme pøíznak a výsledek
				vysledek = X[i][j];
				break;                // a opustíme vnitøní cyklus
			}              // Ve vnìjším cyklu zkontrolujeme, zda jsme se
		}                      // sem dostali po nalezení výsledku, a pokud ano,
		if(nalezeno) break;                   // opustíme i vnìjší cyklus a skonèíme
	}
	return vysledek;
}

int NajdiPrvniZaporne1(int(* X)[n])
{
	int vysledek = 1;           
	for(int i = 0; i < m; i++)                  // Procházíme jednotlivé øádky
	{
		for(int j = 0; j < n; j++)          // Pocházíme jednotlivé prvky v øádku
		{
			if(X[i][j] < 0)             // Když najdeme záporné èíslo,
			{
				vysledek = X[i][j]; // nastavíme výsledek
				goto Konec;         // a opustíme vnitøní cyklus
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
	cout << "První záporné je " << NajdiPrvniZaporne(M) << endl; 
	cout << "První záporné je " << NajdiPrvniZaporne1(M) << endl;
}