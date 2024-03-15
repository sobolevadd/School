// Soubor 04-08\HLAVNI.CPP
// Nejake pouziti seznamu, tentokrat 
// parametrizovaneho pomoci sablon
// a chyby (vyber z prazdneho seznamu) 
// jsou reseny vyjimkami

#include <iostream>
#include <stdexcept>
using namespace std;
#include "seznam.h"

int main()
{
   prvek<int>* p;
   seznam<int> *S = 0;
   try{
	S = new seznam<int>;
	//for(int i = 0; i < 5; i++) S->vlozNaKonec(i);
	cout << ((S->najdi(3,p))? "Je tam" : "neni") << endl; // ?: nutno uzavorkovat
	S->vyjmi(2);
   }
   catch(logic_error e)
   {
	   cerr << "Chyba: " << e.what() << endl;
   }
   catch(bad_alloc e)
   {
	   cerr << "Æhyba: neni pamet" << endl;
   }
   delete S;
}
