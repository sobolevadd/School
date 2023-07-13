#include "Usecka.h"
#include <iostream>

using namespace std;

Usecka::Usecka(int bar, Bod& _pocatek, Bod& _konec)
	: GO(bar), pocatek(_pocatek), konec(_konec)
{
	pocatek.SetBarva(bar);
	konec.SetBarva(bar);
}

Usecka::Usecka(int bar, int x1, int y1, int x2, int y2)
	: GO(bar), pocatek(bar, x1, y1), konec(bar, x2, y2) 
{}

void Usecka::SetPocatek(Bod& _pocatek)
{
	pocatek = _pocatek;
}

void Usecka::SetKonec(Bod& _konec)
{
	konec = _konec;
}

Bod Usecka::GetPocatek()
{
	return pocatek;
}

Bod Usecka::GetKonec()
{
	return konec;
}

void Usecka::Nakresli()
{
	cout <<"[";
	pocatek.Nakresli();
	cout << "; ";
	konec.Nakresli();
	cout << "]";
}