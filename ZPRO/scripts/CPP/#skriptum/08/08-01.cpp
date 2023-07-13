// Soubor 08-01.CPP
// Schematicka ukazka pouziti 
// funkce set_new_handler
// Uklid je handler, ktery se zavola
// pri vycerpani pameti

#include <new>
#include <iostream>
#include <cstdlib>
using namespace std;

void UlozData() {/* ... */}
void ZavriSoubory() {/* ... */}

void Uklid(void) 									// Handler
{ 
	UlozData();
	ZavriSoubory();
	cout << "Je mi líto, nemáme pamì, konèíme..." << endl;
	exit(1);
}
int main()
{
	set_new_handler(Uklid); 				// Nastavíme nový handler
	int *pole = new int [100000]; 		// Pokus o alokaci
	// ...
	return 0;
}
