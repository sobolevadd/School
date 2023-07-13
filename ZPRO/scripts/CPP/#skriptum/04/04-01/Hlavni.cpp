// Soubor 04-01\HLAVNI.CPP
// Nejake pouziti seznamu, tentokrat 
// parametrizovaneho pomoci typedef
// NENI TO VHODNE RESENI, POKUD JSOU SABLONY

#include <iostream>
using namespace std;
#include "seznam.h"

int main()
{
   prvek* p;
   seznam *S = new seznam;
   for(int i = 0; i < 5; i++)
    if(!(S->vlozNaKonec(i))) chyba();
   cout << ((S->najdi(3,p))? "Je tam" : "neni") << endl; // ?: nutno uzavorkovat
   S->vyjmi(2);
   delete S;
}
