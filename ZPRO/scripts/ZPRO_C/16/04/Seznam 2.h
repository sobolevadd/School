#ifndef __SEZNAM_H__
#define __SEZNAM_H__
#include <iostream>
#include "Prvek.h"

using namespace std;

class Seznam
{
	Prvek *hlava, *konec;
public:
	Seznam();
	~Seznam();
	bool prazdny();
	void vlozNakonec(T _data);
	T vyjmiPrvni();
	void setrid(bool (*mensiNez)(void*p1, void* p2));
	void vypis(ostream& proud);
	void vyprazdni();
	Prvek* najdiNejmensi(Prvek* od, bool (*mensiNez)(void*p1, void* p2));
	void prohod(Prvek* p1, Prvek* p2); 
};

#endif