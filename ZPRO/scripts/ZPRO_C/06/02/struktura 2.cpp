#include <iostream>

using namespace std;

struct Datum {                              // struktura popisuj�c� datum
      int den, mesic, rok;
};

enum Stav {Svobodny, Zenaty, Vdana, Rozvedeny, Vdovec, Vdova};

struct  Zamestnanec {                             //  �daje o zam�stnanci
     char Jmeno[30];
     char Prijmeni[50];
     Datum DatumNarozeni;
     Stav stav;
};



int main()
{
	system("CHCP 1250 > NUL");
	Zamestnanec Z1 = {"Jan", "Vopi�ka", {5, 5, 1990}, Svobodny};
	Zamestnanec Z2;
	Zamestnanec Oni[10];
	Z2.DatumNarozeni.den = 13;
	Z2.DatumNarozeni.mesic = 7;
	Z2.DatumNarozeni.rok = 1980;
	strcpy(Z2.Jmeno, "Kyli�n");
	strcpy(Z2.Prijmeni, "P�dlo");
	Z1 = Z2;
	cout << Z1.Prijmeni << ", " << Z1.DatumNarozeni.rok << endl;
}