#include <iostream>
#include <stdlib.h>


using namespace std;

enum Stav {Svobodny, Zenaty, Vdana, Rozvedeny, Vdovec, Vdova};

struct Datum {                              // struktura popisující datum
      int den, mesic, rok;
};

struct  Zamestnanec {                             //  Údaje o zamìstnanci
     char Jmeno[30];
     char Prijmeni[50];
     Datum DatumNarozeni;
     Stav stav;
};

void VypisUdaje(Zamestnanec * on)
{
	cout << on -> Prijmeni << endl << on -> DatumNarozeni.rok << endl;
}


int main()
{
	system("CHCP 1250 > NUL");
	Zamestnanec prodavac = {"Jan", "Novák", {1, 6, 1990}, Svobodny};	
	VypisUdaje(&prodavac);
}