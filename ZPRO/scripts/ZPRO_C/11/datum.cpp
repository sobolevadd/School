#include <iostream>
#include <stdlib.h>


struct Datum {
   int den, mesic, rok;
};


bool Prestupny1(int rok)
{
	return (rok % 100 == 0) ? (rok % 400 == 0) : (rok % 4 == 0);
}

bool Prestupny(int rok)
{
	return !(rok % 100) ? !(rok % 400) : !(rok % 4);
}

void Zitra(Datum& dnes)
{
	const int mesicu = 12;
	int pocetDnu[mesicu+1] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	++dnes.den;
	if(Prestupny(dnes.rok)) pocetDnu[2] = 29;
	if(dnes.den > pocetDnu[dnes.mesic])
	{
		dnes.den = 1;
		++dnes.mesic;
		if(dnes.mesic > mesicu)
		{
			dnes.mesic = 1;
			++dnes.rok;
		}
	}
}

int main()
{
	system("CHCP 1250 > NUL");
	Datum den = {28,2,2013};
	Zitra(den);
	cout << den.den << ". " << den.mesic << ". " << den.rok << endl;
}