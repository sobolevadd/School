// Soubor 15-00G.cpp
// Predefinovani new a delete
// Tyto funkce nahradi globalni new a delete po
// celou dobu behu programu
// Lepsi nez predchozi (15-00F.cpp), nebot
// spolupracuje se set_new_handler() a vraci vzdy alespon 1 bajt
// ale nevyvolava vyjimku

#include <cstdlib>
#include <cstring>
#include <new>

using namespace std;
static new_handler new_hand = 0; 		// Ukazatel na handler
// Tato funkce nastaví novı handler
// a vrátí ukazatel na pùvodní
new_handler set_new_handler(new_handler new_p)
{
	new_handler stary = new_hand;
	new_hand = new_p;
	return stary;
}

void* operator new(size_t s)
{
	s = s ? s : 1; 									// Alespoò 1 bajt
	void *p;
	// Pokud se nepodaøí alokace a ukazatel na handler není 0
	while(((p = malloc(s)) == 0) && (new_hand != 0))
		new_hand(); 										// Zavolej handler
	if(p) memset(p,0,s);							// Inicializuj pamì
	return p;												// Vra ukazatel
}


int main()
{
	int *u = new int;
	delete u;
	return 0;
}