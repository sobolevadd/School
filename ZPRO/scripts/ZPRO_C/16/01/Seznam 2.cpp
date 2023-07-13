#include <stdexcept>
#include <iostream>
#include "Seznam.h"

using namespace std;

Seznam::Seznam()
{
	konec = hlava = nullptr;
}

Seznam::~Seznam()
{
	vyprazdni();
}

void Seznam::vyprazdni()
{
	while (!prazdny())
	{
		vyjmiPrvni();
	}
}

T Seznam::vyjmiPrvni()
{
	if(!prazdny())
	{
		T vysledek = hlava->getData();
		Prvek * pom = hlava;
		hlava = hlava -> getDalsi();
		delete pom;	
		if(prazdny()) 
			konec = nullptr;
		return vysledek;
	}
	else 
		throw out_of_range("Výbìr z prázdného seznamu");
}

void Seznam::vlozNakonec(T co)
{
	Prvek *pom = new Prvek(co, nullptr);
	if(prazdny())
	{
		hlava = konec = pom;
	}
	else
	{
		konec -> setDalsi(pom);
		konec = pom;
	}
}

bool Seznam::prazdny()
{
	return hlava == nullptr;
}

void Seznam::prohod(Prvek* p1, Prvek * p2)
{
	T pom = p1->getData();
	p1 -> setData(p2->getData());
	p2 -> setData(pom);
}

Prvek* Seznam::najdiNejmensi(Prvek* od)
{
	Prvek * pom = od;
	T hod = pom->getData();
	while(od != konec)
	{
		od = od->getDalsi();
		if(od->getData() < hod)
		{
			hod = od->getData();
			pom = od;
		}
	}
	return pom;
}

void Seznam::setrid()
{
	Prvek* od = hlava;
	while(od != konec)
	{
		Prvek * nejmensi = najdiNejmensi(od);
		if(nejmensi != od)
			prohod(nejmensi, od);
		od = od->getDalsi();
	}
}

void Seznam::vypis(ostream& proud)
{
	Prvek * pom = hlava;
	while(pom)
	{
		proud << pom->getData() << " ";
		pom = pom->getDalsi();
	}
	proud <<endl;
}