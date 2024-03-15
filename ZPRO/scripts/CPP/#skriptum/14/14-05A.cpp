// Soubor 14-05A.cpp
// Podobne jako 14-05.cpp, az na to, ze
// konstruktor 2 je nyni déklarovan jako 
// explicitni,takze prekladac odhali chybu
// pri volani funkce Ha()

#include <iostream>
using namespace std;

class pole {
	int *p, delka;
public:
	pole();							// Konstruktor è. 1
	explicit pole(int, int=10); 				// Konstruktor è. 2
	pole(pole&); 					// Kopírovací konstruktor
	~pole();						// Destruktor
	// ...a další metody
};

pole::pole(int n, int d)
: p(0), delka(n)
{
	p = new int [delka];
	for(int i = 0; i < n; i++) p[i] = d;
}

pole::pole()
: p(0), delka(0){}

pole::~pole()
{ 
	delete[] p;
}

pole::pole(pole& t)					// Kopírovací konstruktor
: p(0), delka(t.delka)
{
	p = new int [delka];			// Alokuje nové pole p
									// a pøekopíruje do nìj obsah t.p
	for(int i = 0; i < delka; i++) p[i] = t.p[i];
}

void Ha(pole p)
{}					// Na tom, co dìlá, nezáleží

int main()
{
	try{
		pole p(10, 999);// Použije se konstruktor è. 2
		pole q(45);		// Použije se konstruktor è. 2
		pole r; 		// Použije se konstruktor è. 1
		pole s(); 		// Prototyp funkce, nikoli deklarace instance!!
		pole t(p);		// Použije se kopíroavcí konstruktor

		Ha(1);			// Nyni prekladac ohlasi chybu,
	}					// nebot konstruktor je explicitni
	catch(std::bad_alloc b)
	{
		cerr << "nepodarilo se vytvorit instanci pole" << endl;
	}
}