#include <iostream>
#include <stdlib.h>


using namespace std;

enum Stav {Svobodny, Zenaty, Vdana, Rozvedeny, Vdovec, Vdova};

struct Datum {                              // struktura popisuj�c� datum
      int den, mesic, rok;
};

struct  Zamestnanec {                             //  �daje o zam�stnanci
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
	Zamestnanec prodavac = {"Jan", "Nov�k", {1, 6, 1990}, Svobodny};	
	VypisUdaje(&prodavac);
}