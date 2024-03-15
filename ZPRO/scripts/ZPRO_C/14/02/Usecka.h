#ifndef __USECKA_H__
#define __USECKA_H__
#include "GO.h"
#include "Bod.h"

class Usecka : public GO
{
	Bod pocatek, konec;
public:
	Usecka(int bar, Bod& _pocatek, Bod& _konec);
	Usecka(int bar, int x1, int y1, int x2, int y2);
	virtual void Nakresli();
	Bod GetPocatek();
	void SetPocatek(Bod& _pocatek);
	Bod GetKonec();
	void SetKonec(Bod& _konec);
};
#endif